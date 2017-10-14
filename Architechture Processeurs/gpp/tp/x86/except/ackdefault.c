/*
* file ackdefaut.c
* brief génération exception matériel, détournement procédure de traitement des
* signaux UNIX pour le processus courant et acquittement du défaut
* author 
*/

#include <stdio.h>
#define __USE_GNU
#include <signal.h>
#include <ucontext.h>

/*
* procédure de traitement des signaux UNIX pour le processus courant
*/
void signal_handler(int signb, siginfo_t* signinfo, ucontext_t* context){
	char dummy = 'a';

	printf("\n *** signal handler\n");
	
	/* à compléter ! */
}

/*
* program entry point
*/
int main(int argc, char **argv) {
	struct sigaction sigact;
	sigset_t sset;
	char *ptr = NULL;
	char tmp;

	// signal configuation
/*	sigemptyset(&sset);
	sigaddset(&sset, SIGSEGV); 
	sigact.sa_flags = SA_SIGINFO ;
	sigact.sa_mask = sset;
	sigact.sa_sigaction = (void*) signal_handler;
	sigaction(SIGSEGV, (const struct sigaction *) &sigact, NULL);
*/
	// force hardware exception by writing dereferencing pointerin eax register
	printf("hardware exception has been generated\n");
	tmp = *ptr;

	printf("\nexception has been acknowledged, tmp = '%c'\n", tmp);
return 0;
}
