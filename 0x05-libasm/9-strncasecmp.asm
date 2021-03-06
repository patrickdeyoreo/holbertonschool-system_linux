BITS 64
	global asm_strncasecmp	; export 'asm_strncasecmp' function

	section .text

	; int asm_strncasecmp(const char *s1, const char *s2, size_t n);
	; Lexicographically compare at most n bytes of two strings
	;
	; rdi <- s1
	; rsi <- s2
	; rdx <- n
	;
	; Return: a value less than, equal to, or greater than zero if s1 is
	; found to be, respectively, less than, equal to, or greater than s2

asm_strncasecmp:
			; the following two lines are equivalent to ENTER
	push rbp	; save frame pointer
	mov rbp, rsp	; create new frame

	push rcx	; save @rcx

asm_strncasecmp_loop:

	cmp rdx, 0h		; compare @rdx with 0
	je asm_strncasecmp_eq	; jump to "eq" if @rdx is equal to 0

	mov cl,	[rdi]		; copy the byte at @rdi into @cl
	mov ch,	[rsi]		; copy the byte at @rsi into @ch

	cmp cl,	ch		; compare @cl with @ch
	jl asm_strncasecmp_lt	; jump to "lt" if @cl is less than @ch
	jg asm_strncasecmp_gt	; jump to "gt" if @cl is greater than @ch

	cmp cl,	0h		; compare @cl with 0
	je asm_strncasecmp_eq	; jump to "eq" if @cl is equal to 0

	inc rdi			; increment @rdi
	inc rsi			; increment @rsi
	dec rdx			; decrement @rdx
	jmp asm_strncasecmp_loop	; jump to the beginning of the loop

asm_strncasecmp_lt:

	mov eax, -1h		; return -1

	jmp asm_strncasecmp_end	; jump to "end"

asm_strncasecmp_gt:

	mov eax, 1h		; return 1

	jmp asm_strncasecmp_end	; jump to "end"

asm_strncasecmp_eq:

	mov eax, 0h		; return 0

asm_strncasecmp_end:

	pop rcx		; restore @rcx

			; the following two lines are equivalent to LEAVE
	mov rsp, rbp	; restore stack pointer
	pop rbp		; restore frame pointer

	ret		; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
