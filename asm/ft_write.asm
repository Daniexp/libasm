section .text
	global ft_write
	extern __errno_location
ft_write:
	mov rax, 1
	syscall

	cmp rax, 0
	jbe .end
.error
	neg rax
	mov rdi, rax
	call __errno_location
	mov [rax], edi

	mov rax, -1
	ret
.end:
	ret
