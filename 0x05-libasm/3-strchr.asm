BITS 64
	global asm_strchr	; export 'asm_strchr' function

	section .text

	; char *asm_strchr(const char *s, int c);
	; Locate a character in a string
	;
	; rdi <- s
	; rsi <- c
	;
	; Return: pointer to the first occurrence of character c in string s

asm_strchr:
			; the following two lines are equivalent to ENTER
	push rbp	; save frame pointer
	mov rbp, rsp	; create new frame

asm_strchr_loop:

	cmp byte [rdi], sil	; compare @dl with 0
	je asm_strchr_end	; jump to "end" if @dl is equal to 0

	cmp byte [rdi], 0h	; compare @dl with 0
	je asm_strchr_nomatch	; jump to "end" if @dl is equal to 0

	inc rdi			; increment offset
	jmp asm_strchr_loop	; jump to the beginning of the loop

asm_strchr_nomatch:

	mov rdi, 0h	; copy 0 into @rdi

asm_strchr_end:

	mov rax, rdi	; return the value stored in @rsi

			; the following two lines are equivalent to LEAVE
	mov rsp, rbp	; restore stack pointer
	pop rbp		; restore frame pointer

	ret		; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
