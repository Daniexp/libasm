;char *strdup(char *str)
;void *malloc(size_t size)

section .text
	extern malloc
	extern ft_strlen
	extern ft_strcpy
	global ft_strdup
ft_strdup:
	push rbp
	mov rbp, rsp ; setup stack frame

	push rdi ; save original string pointer

	call ft_strlen
	inc rax
	mov rdi, rax ; size of the new string (including null terminator)

	call malloc wrt ..plt
	cmp rax, 0
	je .end

	mov rdi, rax ; new allocated memory address
	pop rsi ; restore original string pointer
	call ft_strcpy

	mov rsp, rbp
	pop rbp ; teardown stack frame
.end:
	ret

