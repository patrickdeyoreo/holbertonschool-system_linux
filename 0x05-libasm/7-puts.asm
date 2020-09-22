BITS 64
	global asm_puts		; export 'asm_puts' function

	extern asm_strlen	; import 'asm_strlen' function

	section .text

	; size_t asm_puts(const char *str);
	; Write a string to stdout
	;
	; rdi <- str
	;
	; Return: the number of bytes written

asm_puts:

	push rbp		; save frame pointer
	mov rbp, rsp		; create new frame

	sub rsp, 12		; increase the size of the stack by 12 bytes

	mov [rsp], rdi		; save a pointer to the string on the stack

	call asm_strlen		; call 'asm_strlen' function
	mov [rsp - 8], eax	; save the length of the string on the stack

	mov rax, 1		; write system call
	mov rdi, 1		; stdout fileno
	mov edx, [rsp - 8]	; number of bytes to write
	mov rsi, [rsp]		; pointer to byte to write

	syscall			; trap to kernel

asm_puts_end:

	add rsp, 12		; decrease the size of the stack by 12 bytes

	mov rsp, rbp		; restore stack pointer
	pop rbp			; restore frame pointer

	ret			; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
