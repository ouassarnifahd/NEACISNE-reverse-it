	.file	"function.c"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$1, %edi
	call	inc
	movl	%eax, -4(%rbp)
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.globl	inc
	.type	inc, @function
inc:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, %eax
	addl	$1, %eax
	popq	%rbp
	ret
	.size	inc, .-inc
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
