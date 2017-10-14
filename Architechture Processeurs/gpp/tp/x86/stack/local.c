/*
* file local.c
* brief programme d'analyse des mécanismes de gestion de la pile
* author 
*/

/*
* program entry point
*/
int main(void){
	char foo;
	unsigned int bar;

return 0;
}

/*
	.file	"local.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$0, %eax
	popl	%ebp
	ret
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
*/