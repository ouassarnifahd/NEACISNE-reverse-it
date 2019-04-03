#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXCAR 100

int main () {
    int tube12[2], tube21[2], pid, i ,t ;
    char buf[MAXCAR] ;
    pipe (tube12) ; pipe (tube21) ;
    pid = fork() ;
    if (pid == 0) {
        for(;;) {
	    close(tube12[1]) ; close(tube21[0]) ; //fermeture des extrémités inutiles
            t=read ( tube12[0], buf, MAXCAR) ; if (t <= 0) { perror("read "); _exit (0); }
            for(i = 0 ; i < t ; i++) if (buf[i] >='a' && buf[i] <='z') buf[i] = buf[i]-32 ;
            t=write ( tube21[1], buf, t) ;
        }
    }
    else {  
		do {
				close(tube12[0]) ; close(tube21[1]) ; //fermeture des extrémités inutiles
                printf ("phrase : \n") ; scanf ("%s",buf);
                t=write( tube12[1], buf, strlen(buf)) ;
                t=read ( tube21[0], buf, MAXCAR) ; 
                printf ("\ttraduction : %s \n", buf);
            } while (strncmp ("QUIT", buf, 4) ) ;
            kill (pid, SIGKILL);
            close(tube12[1]) ;  close(tube21[0]) ;
            wait (&i);
   }
}
