	.file	"static.c"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movzbl	foo.1833(%rip), %eax
	addl	$1, %eax
	movb	%al, foo.1833(%rip)
	movl	$0, %eax
	popq	%rbp
	ret
	.size	main, .-main
	.data
	.type	foo.1833, @object
	.size	foo.1833, 1
foo.1833:
	.byte	97
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
