BITS 64
	global asm_strspn		; export 'asm_strspn' function

	section .text

	; size_t asm_strspn(const char *s, const char *accept);
	; Get the length of a prefix substring
	;
	; rdi <- s
	; rsi <- accept
	;
	; Return: the number of bytes in the initial segment of s which consist
	; only of bytes from accept

asm_strspn:

	push rbp			; save frame pointer
	mov rbp, rsp			; create new frame

	sub rsp, 16			; increase the size of the stack by 16 bytes

	mov [rsp - 8], rdi		; save @s on the stack

asm_strspn_loop:

	mov dl, [rdi]			; copy the byte at @rdi into @dl

	cmp dl, 0			; compare 0 with @dl
	je asm_strspn_end		; jump to "end" if @dl is equal to 0

	mov [rsp], rsi			; save @accept on the stack

asm_strspn_accept:

	cmp byte [rsi], 0		; compare 0 with the byte at @rsi
	je asm_strspn_end		; jump to "end" if the byte at @rsi is equal to 0

	cmp dl, [rsi]			; compare the byte at @rsi with @dl
	je asm_strspn_continue		; jump to "continue" if @dl is equal to the byte at @rsi

	inc rsi				; increment @rsi

	jmp asm_strspn_accept		; jump to "accept"

asm_strspn_continue:

	mov rsi, [rsp]			; restore @rsi from the stack

	inc rdi				; increment @rdi

	jmp asm_strspn_loop		; jump to the beginning of the loop

asm_strspn_end:

	sub rdi, [rsp - 8]		; substract @s from @rdi

	mov rax, rdi			; return the difference between @s and @rdi

	add rsp, 16			; decrease the size of the stack by 16 bytes

	mov rsp, rbp			; restore stack pointer
	pop rbp				; restore frame pointer

	ret				; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
