#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, char** argv) {
    int pid, ret;
    char commande[20], arg1[30] , cheminExe [40];
    for (; ; ) {
        printf("Entrez la commande > ");
        scanf ("%s %s", commande, arg1);
        sprintf (cheminExe, "/bin/%s", commande);
        pid = fork();
        if (pid == 0) {
            execl(cheminExe, commande, arg1, NULL);
        }
        wait (&ret); 
    }
    return(EXIT_SUCCESS);
}

