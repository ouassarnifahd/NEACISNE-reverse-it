/*
* file main.c
* brief programme d'analyse des m�canismes de gestion de la pile
* author 
*/

/*
* program entry point
*/
int main(void){
/* pushl %ebp : sauvegarde le contexte de la fonction appelante
movl %esp, %ebp : pr�paration � l'allocation de ressources m�moire
pour le contexte de la fonction courante ou fonction main ---> contenu de
la pile repr�sent� ci-contre apr�s ex�cution de cette instruction */
return 0;
/* movl $0, %eax : passage par registre de la valeur de retour
popl %ebp : restaure le contexte de la fonction appelante
ret : d�pile l'adresse de retour de la fonction appelante et la charge
dans le pointeur d'instruction puis quitte la fonction main */
}

