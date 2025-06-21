; char *strcpy(char *dest, const char *src)

section .text
	global ft_strcpy

ft_strcpy:
	xor rcx, rcx
.loop:
	cmp byte [rsi + rcx], 0
	je .done
	mov bl, [rsi + rcx]
	mov [rdi + rcx], bl
	inc rcx
	jmp .loop
.done:
	mov byte [rdi + rcx], 0
	mov rax, rdi
	ret
