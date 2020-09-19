BITS 64
	global asm_memcpy	; export 'asm_memcpy' function

	section .text

	; void *asm_memcpy(void *dest, const void *src, size_t n);
	; Copy memory area
	;
	; rdi <- s1
	; rsi <- s2
	; rdx <- n
	;
	; Return: pointer to dest

asm_memcpy:
			; the following two lines are equivalent to ENTER
	push rbp	; save frame pointer
	mov rbp, rsp	; create new frame

	mov rax, rdi	; copy @rdi into @rax

	push rcx	; save @rcx

asm_memcpy_loop:

	cmp rdx, 0h		; compare 0 with @rdx
	je asm_memcpy_end	; jump to "end" if @rdx is equal to 0

	mov cl,	[rsi]		; copy the byte at @rsi into @cl
	mov [rdi], cl		; copy @cl into the byte at @rdi

	inc rdi			; increment @rdi
	inc rsi			; increment @rsi
	dec rdx			; decrement @rdx
	jmp asm_memcpy_loop	; jump to the beginning of the loop

asm_memcpy_end:

	pop rcx		; restore @rcx

			; the following two lines are equivalent to LEAVE
	mov rsp, rbp	; restore stack pointer
	pop rbp		; restore frame pointer

	ret		; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
