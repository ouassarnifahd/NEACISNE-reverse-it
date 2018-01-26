	.file	"heap.c"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$100, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$7, %rax
	movb	$1, (%rax)
	movq	-8(%rbp), %rax
 	movl	$120, %esi
	movq	%rax, %rdi
	call	realloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$10, %rax
	movb	$97, (%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
