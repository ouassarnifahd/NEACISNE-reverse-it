/*
* file init.c
* brief programme d'analyse des mécanismes de gestion de la pile
* author 
*/

/*
* program entry point
*/
int main(void){
	char foo = 1;
	unsigned int bar = 2;
	
	foo = (char) bar;
	
return 0;
}

/*
	.file	"init.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movb	$1, -5(%ebp)
	movl	$2, -4(%ebp)
	movl	-4(%ebp), %eax
	movb	%al, -5(%ebp)
	movl	$0, %eax
	leave
	ret
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
*/
