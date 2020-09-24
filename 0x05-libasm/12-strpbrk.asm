BITS 64
	global asm_strpbrk		; export 'asm_strpbrk' function

	section .text

	; char *asm_strpbrk(const char *s, const char *accept);
	; Search a string for any of a set of bytes
	;
	; rdi <- s
	; rsi <- accept
	;
	; Return: a pointer to the byte in s that matches a byte in accept, or
	; NULL if no such byte is found

asm_strpbrk:

	push rbp			; save frame pointer
	mov rbp, rsp			; create new frame

	xor rax, rax			; zero-initialize @rax

	sub rsp, 8			; increase the size of the stack by 8 bytes

asm_strpbrk_loop:

	mov dl, [rdi]			; copy the byte at @rdi into @dl

	cmp dl, 0			; compare 0 with @dl
	je asm_strpbrk_end		; jump to "end" if @dl is equal to 0

	mov [rsp], rsi			; save @accept on the stack

asm_strpbrk_accept:

	cmp byte [rsi], 0		; compare 0 with the byte at @rsi
	je asm_strpbrk_continue		; jump to "continue" if the byte at @rsi is equal to 0

	cmp dl, [rsi]			; compare the byte at @rsi with @dl
	je asm_strpbrk_match		; jump to "end" if @dl is equal to the byte at @rsi

	inc rsi				; increment @rsi

	jmp asm_strpbrk_accept		; jump to "accept"

asm_strpbrk_continue:

	mov rsi, [rsp]			; restore @rsi from the stack

	inc rdi				; increment @rdi

	jmp asm_strpbrk_loop		; jump to the beginning of the loop

asm_strpbrk_match:

	mov rax, rdi			; return @rdi

asm_strpbrk_end:

	add rsp, 8			; decrease the size of the stack by 8 bytes

	mov rsp, rbp			; restore stack pointer
	pop rbp				; restore frame pointer

	ret				; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
