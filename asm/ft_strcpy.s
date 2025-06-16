extern ft_strlen
; char *strcpy(char *dest, const char *src)

section .text
	global ft_strcpy

ft_strcpy:
	call ft_strlen
	ret
