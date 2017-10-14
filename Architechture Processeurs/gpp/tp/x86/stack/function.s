	.file	"function.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx

	subl	$20, %esp
	subl	$12, %esp

	pushl	$1
	call	inc

	addl	$16, %esp
	movb	%al, -9(%ebp)
	
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
.LFE0:
	.size	main, .-main
	.globl	inc
	.type	inc, @function
inc:
.LFB1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	8(%ebp), %eax
	movb	%al, -4(%ebp)
	movzbl	-4(%ebp), %eax
	addl	$1, %eax
	leave
	ret
.LFE1:
	.size	inc, .-inc
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
