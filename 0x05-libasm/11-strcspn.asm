BITS 64
	global asm_strcspn		; export 'asm_strcspn' function

	section .text

	; size_t asm_strcspn(const char *s, const char *reject);
	; Get the length of a prefix substring
	;
	; rdi <- s
	; rsi <- reject
	;
	; Return: the length of the initial segment of s which consists
	; entirely of bytes not in reject

asm_strcspn:

	push rbp			; save frame pointer
	mov rbp, rsp			; create new frame

	sub rsp, 16			; increase the size of the stack by 16 bytes

	mov [rsp - 8], rdi		; save @s on the stack

asm_strcspn_loop:

	mov dl, [rdi]			; copy the byte at @rdi into @dl

	cmp dl, 0			; compare 0 with @dl
	je asm_strcspn_end		; jump to "end" if @dl is equal to 0

	mov [rsp], rsi			; save @reject on the stack

asm_strcspn_reject:

	cmp byte [rsi], 0		; compare 0 with the byte at @rsi
	je asm_strcspn_continue		; jump to "continue" if the byte at @rsi is equal to 0

	cmp dl, [rsi]			; compare the byte at @rsi with @dl
	je asm_strcspn_end		; jump to "end" if @dl is equal to the byte at @rsi

	inc rsi				; increment @rsi

	jmp asm_strcspn_reject		; jump to "reject"

asm_strcspn_continue:

	mov rsi, [rsp]			; restore @rsi from the stack

	inc rdi				; increment @rdi

	jmp asm_strcspn_loop		; jump to the beginning of the loop

asm_strcspn_end:

	sub rdi, [rsp - 8]		; substract @s from @rdi

	mov rax, rdi			; return the difference between @s and @rdi

	add rsp, 16			; decrease the size of the stack by 16 bytes

	mov rsp, rbp			; restore stack pointer
	pop rbp				; restore frame pointer

	ret				; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
