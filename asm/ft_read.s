; ssize_t read(int fd, void *buf, size_t count)
section .text
	global ft_read
	extern __errno_location
ft_read:
	mov rax, 0
	syscall

	cmp rax, 0
	jge .end
.error:
	neg rax
	mov rdi, rax
	call __errno_location wrt ..plt
	mov [rax], edi

	mov rax, -1
	ret
.end:
	ret
