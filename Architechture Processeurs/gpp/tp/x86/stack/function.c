/*
* file function.c
* brief programme d'analyse des mécanismes de gestion de la pile
* author 
*/

/* privates prototypes */
//inline char inc(char bar) __attribute__((always_inline));
char inc(char bar);

/*
* program entry point
*/
int main(void){
	// andl		$-16, %esp
	// pushl	%ebp
	// movl		%esp, %ebp


	// subl		$20, %esp
	// subl		$12, %esp
	char foo;

		// pushl	$1
		// call		inc
	foo = inc(1);
	// addl	$16, %esp
	// movb	%al, -9(%ebp)

return 0;
// movl	$0, %eax
// leave
}

/*
 * function incrémentant la valeur d'entrée
 */
//inline char inc(char bar) {
char inc(char bar) {
return bar+1;
}

