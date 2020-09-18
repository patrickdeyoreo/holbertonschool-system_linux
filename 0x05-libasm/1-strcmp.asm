BITS 64
	global asm_strcmp	; export 'asm_strcmp' function

	section .text

	; int asm_strcmp(const char *s1, const char *s2);
	; Lexicographically compare two strings
	;
	; rdi <- s1
	; rsi <- s2
	;
	; Return: a value less than, equal to, or greater than zero if s1 is
	; found to be, respectively, less than, equal to, or greater than s2

asm_strcmp:
			; the following two lines are equivalent to ENTER
	push rbp	; save frame pointer
	mov rbp, rsp	; create new frame

	push rdx	; save @rdx

asm_strcmp_loop:

	mov dl,	[rdi]		; copy the byte at @rdi into @dl
	mov dh,	[rsi]		; copy the byte at @rsi into @dh

	cmp dl,	dh		; compare @dl with @dh
	jl asm_strcmp_lt	; jump to "lt" if @dl is less than @dh
	jg asm_strcmp_gt	; jump to "gt" if @dl is greater than @dh

	cmp dl,	0h		; compare @dl with 0
	je asm_strcmp_eq	; jump to "eq" if @dl is equal to 0

	inc rdi			; increment @rdi
	inc rsi			; increment @rsi
	jmp asm_strcmp_loop	; jump to the beginning of the loop

asm_strcmp_lt:

	mov eax, -1h		; return -1

	jmp asm_strcmp_end	; jump to "end"

asm_strcmp_gt:

	mov eax, 1h		; return 1

	jmp asm_strcmp_end	; jump to "end"

asm_strcmp_eq:

	mov eax, 0h		; return 0

asm_strcmp_end:

	pop rdx		; restore @rdx

			; the following two lines are equivalent to LEAVE
	mov rsp, rbp	; restore stack pointer
	pop rbp		; restore frame pointer

	ret		; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
