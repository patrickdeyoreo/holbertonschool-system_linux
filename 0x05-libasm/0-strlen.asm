BITS 64
	global asm_strlen	; export 'asm_strlen' function

	section .text

	; size_t asm_strlen(const char *str);
	; Measure the length of a string
	;
	; rdi <- str
	;
	; Return: the length of the string pointed to by str

asm_strlen:

	push rbp		; save frame pointer
	mov rbp, rsp		; create new frame

	mov rsi, 0h		; copy 0 into @rsi

asm_strlen_loop:

	mov dl, [rdi + rsi]	; copy the byte at @rdi + @rsi into @dl

	cmp dl, 0h		; compare @dl with 0
	je asm_strlen_end	; jump to "end" if @dl is equal to 0

	inc rsi			; increment offset
	jmp asm_strlen_loop	; jump to the beginning of the loop

asm_strlen_end:

	mov rax, rsi		; return the value stored in @rsi

	mov rsp, rbp		; restore stack pointer
	pop rbp			; restore frame pointer

	ret			; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
