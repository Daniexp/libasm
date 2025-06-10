section .data
	msg db "OK", 0xA ; Declare const string and add \n in hexadecimal
	len equ $- msg ; Calculate const label length

section .text
	global _start

_start:
	mov rax, 1 ; syscall: write - rd1 fd, rs1 *buf, rdx count
	mov rdi, 1 ; file descriptor: stdout
	mov rsi, msg ; move msg to *buf
	mov rdx, len ; move len to *count
	syscall

	mov rax, 60 ; syscall: exit
	xor rdi, rdi ; status code: 0 -> using XOR to clear register
	syscall
