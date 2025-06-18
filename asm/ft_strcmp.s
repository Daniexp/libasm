;int strcmp(const char *str1, const char *str2)
section .text
	global ft_strcmp
ft_strcmp:
	xor rcx, rcx
	xor rax, rax
	xor rbx, rbx
.loop:
	mov al, [rdi + rcx]
	mov bl, [rsi + rcx]
	cmp al, bl
	jne .not_equal
	cmp al, 0
	je .done
	inc rcx
	jmp .loop
.not_equal:
	movzx rax, al
	movzx rbx, bl
	sub eax, ebx
.done:
	ret
