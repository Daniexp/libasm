section .data
	msg db "Hello World!", 0xA ; Declare const string and add \n in hexadecimal
	len equ $- msg ; Calculate const label length

section .text
	global helloWorld

helloWorld:
	mov rax, 1 ; syscall: write - rd1 fd, rs1 *buf, rdx count
	mov rdi, 1 ; file descriptor: stdout
	lea rsi, [rel msg] ; load effective address of msg into rsi
	mov rdx, len ; move len to *count
	syscall
	ret
