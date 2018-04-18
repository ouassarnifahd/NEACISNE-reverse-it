	.file	"global.c"
	.globl	foo

	.data
	.align 32
	.type	foo, @object
	.size	foo, 1000000
foo:
	.byte	97
	.zero	999999

	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	$65, foo(%rip)
	movl	$0, %eax
	popq	%rbp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
