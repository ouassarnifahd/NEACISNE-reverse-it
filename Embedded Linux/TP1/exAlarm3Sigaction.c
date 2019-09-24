#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>



void maFonc (int noSignal, siginfo_t *si, void *v_ucontext) {
    if (noSignal==SIGINT) {
		printf ("Réveillé par [CTRL] [C]\n");
	}
	else {
		alarm(1);
		printf (" tps = %d\n", time(NULL));
	}
}

int main () {
	struct sigaction sa;
    sa.sa_flags = SA_SIGINFO; // précise qu'il faut utiliser le handler à 3 paramètres
    sigemptyset(&sa.sa_mask); // spécifie qu' aucun signal ne sera bloqué
    sa.sa_sigaction = maFonc;
    if (sigaction(SIGALRM, &sa, NULL) == -1) { perror("sigaction 1"); exit(-1) ;}
    if (sigaction(SIGINT, &sa, NULL) == -1) { perror("sigaction 2"); exit(-1) ;}
    alarm (2) ;
    while(1);
    return (EXIT_SUCCESS);
}
