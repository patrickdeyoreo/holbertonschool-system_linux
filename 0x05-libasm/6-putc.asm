BITS 64
	global asm_putc	; export 'asm_putc' function

	section .text

	; size_t asm_putc(int c);
	; Write a character to stdout
	;
	; rdi <- c
	;
	; Return: the number of bytes written

asm_putc:

	push rbp		; save frame pointer
	mov rbp, rsp		; create new frame

	sub rsp, 1		; increase the size of the stack by 1 byte
	mov [rsp], dil		; store @c on the stack

	mov rax, 1		; write system call
	mov rdi, 1		; stdout fileno
	mov rdx, 1		; number of bytes to write
	mov rsi, rsp		; pointer to byte to write

	syscall			; trap to kernel

asm_putc_end:

	add rsp, 1		; decrease the size of the stack by 1 byte

	mov rsp, rbp		; restore stack pointer
	pop rbp			; restore frame pointer

	ret			; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
