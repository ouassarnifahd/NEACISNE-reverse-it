#include <stdio.h>
#include <stdlib.h>
#define __USE_GNU
#include <signal.h>
#include <ucontext.h>


int *p=NULL ;

void maFonctionHandler (int noSig, siginfo_t *si, void *v_ucontext) {
    printf (" Pb SIGSEGV ! \n");
    ucontext_t *u = (ucontext_t *)v_ucontext; // Le contexte du processus fautif est sauvegardé sur la pile. v_ucontext est une structure permettant de modifier la pile.
    int *newp = (int*) malloc(sizeof(int));
    p = newp ;
    
    u->uc_mcontext.gregs[REG_RAX]= (greg_t) newp; // modification de RAX car l'intruction qui a planté est "movl	$7, (%rax) "
    //on sort du handler et le context est restitué
}   

int main () {
	struct sigaction sa;
    sa.sa_flags = SA_SIGINFO; // précise qu'il faut utiliser le handler à 3 paramètres
    sigemptyset(&sa.sa_mask); // spécifie qu' aucun signal ne sera bloqué
    sa.sa_sigaction = maFonctionHandler;
    // sa.sa_handler non utilisé à cause de SA_SIGINFO sur les flags
    if (sigaction(SIGSEGV, &sa, NULL) == -1) { perror("sigaction"); exit(-1) ;}

    
    *p =7 ;
    printf("Cool ! *p = %d\n", *p);
    return (0);
}

