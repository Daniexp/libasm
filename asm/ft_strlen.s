section .text
	global ft_strlen
; size_t	ft_strlen(const char *str)
ft_strlen:
	xor rax, rax
	; end the function
.loop:
	cmp byte [rdi + rax], 0
	je .done
	inc rax
	jmp .loop
.done:
	ret
