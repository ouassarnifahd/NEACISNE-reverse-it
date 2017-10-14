.section .text 
.global _start

_start:
	mov 	$0, %ebp
	push 	%ebp
	mov 	%esp, %ebp
	call 	main
_trap:
	jmp		_trap
	pop  	%ebp
	ret

	