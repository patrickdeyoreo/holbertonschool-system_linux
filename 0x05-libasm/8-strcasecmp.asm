BITS 64
	global asm_strcasecmp	; export 'asm_strcasecmp' function

	section .text

	; int asm_strcasecmp(const char *s1, const char *s2);
	; Lexicographically compare two strings (case-insensitive)
	;
	; rdi <- s1
	; rsi <- s2
	;
	; Return: a value less than, equal to, or greater than zero if s1 is
	; found to be, respectively, less than, equal to, or greater than s2

asm_strcasecmp:

	push rbp		; save frame pointer
	mov rbp, rsp		; create new frame

	sub rsp, 1		; increase the size of the stack by 1 byte


asm_strcasecmp_loop:

	mov byte [rsp], 0	; initialize flag to zero

	mov dl,	[rdi]		; copy the byte at @rdi into @dl
	mov dh,	[rsi]		; copy the byte at @rsi into @dh

	cmp dl, 65		;

	cmp dl,	dh		; compare @dl with @dh
	jl asm_strcasecmp_lt	; jump to "lt" if @dl is less than @dh
	jg asm_strcasecmp_gt	; jump to "gt" if @dl is greater than @dh

	cmp dl,	0h		; compare @dl with 0
	je asm_strcasecmp_eq	; jump to "eq" if @dl is equal to 0

	inc rdi			; increment @rdi
	inc rsi			; increment @rsi
	jmp asm_strcasecmp_loop	; jump to the beginning of the loop

asm_strcasecmp_lt:

	mov eax, -1h		; return -1

	jmp asm_strcasecmp_end	; jump to "end"

asm_strcasecmp_gt:

	mov eax, 1h		; return 1

	jmp asm_strcasecmp_end	; jump to "end"

asm_strcasecmp_eq:

	mov eax, 0h		; return 0

asm_strcasecmp_end:

	mov rsp, rbp		; restore stack pointer
	pop rbp			; restore frame pointer

	ret			; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
