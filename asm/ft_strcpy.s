; char *strcpy(char *dest, const char *src)

section .text
	global ft_strcpy

ft_strcpy:
	xor rax, rax
.loop:
	cmp byte [rsi + rax], 0
	je .done
	mov bl, [rsi + rax]
	mov [rdi + rax], bl
	inc rax
	jmp .loop
.done:
	mov byte [rdi + rax], 0
	mov rax, rdi
	ret
