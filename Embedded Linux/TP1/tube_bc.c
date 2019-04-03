#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define _NESTED_RW_
//#define _STDIO_REDIRECT_

#define SIZE_BUFFER 128

#define error(MSG, ...) do {\
    perror(MSG, ##__VA_ARGS__);\
    exit(EXIT_FAILURE);\
} while(0)

int main () {
    int pipe12[2], pipe21[2], pid, ret;
    char buffer[SIZE_BUFFER];

    // make 2 pipes (RD and WR)
    if (pipe(pipe12) < 0) error("pipe12"); 
    if (pipe(pipe21) < 0) error("pipe21");

    // create a child process
    if ((pid = fork()) < 0) error("fork");
    // pipes flow 101:
    //            (1)            (stdin)    (2)    (stdout)           (1)
    // stdin -> parent -> 12[1] | 12[0] -> child -> 21[1] | 21[0] -> parent -> stdout
    //        write(12[1])               {12[0], 0}
    //                                   {21[1], 1}                read(21[0])
    if (pid == 0) { // child
        // close unused half of pipes
        close(pipe12[1]); close(pipe21[0]);
        // replace standard input with input part of pipe
        if (dup2(pipe12[0], STDIN_FILENO) < 0) error("dup2(12[0],0)");
        // replace standard output with output part of pipe
        if (dup2(pipe21[1], STDOUT_FILENO) < 0) error("dup2(21[1],1)");
        // execute bc
        execl("/usr/bin/bc", "bc", "-q", NULL);
    } else { // father
        // close unused half of pipes
        close(pipe12[0]); close(pipe21[1]);
        #if defined(_STDIO_REDIRECT_)
        // replace output part of pipe with standard input
        if (dup2(STDIN_FILENO, pipe12[1]) < 0) error("dup2(0,12[1])");
        // replace input part of pipe with standard output
        if (dup2(STDOUT_FILENO, pipe21[0]) < 0) error("dup2(1, 21[0])");
        // child linked lets wait
        wait(&ret);
        #elif defined(_NESTED_RW_)
        int toRead = 0, toWrite = 0;
        do {
            // get standard input
            toRead = read(STDIN_FILENO, buffer, SIZE_BUFFER);
            // write to write part of pipe
            write(pipe12[1], buffer, toRead);
            // read from read part of pipe
            toWrite = read(pipe21[0], buffer, SIZE_BUFFER);
            // set standard output
            write(STDIN_FILENO, buffer, toWrite);
        } while(strncmp(buffer, "quit", 4));
        #endif
        // closing the pipes
        close(pipe12[1]); close(pipe21[0]);
    }
    return EXIT_SUCCESS;
}
