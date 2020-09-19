BITS 64
	global asm_strstr	; export 'asm_strstr' function

	section .text

	; char *asm_strstr(const char *haystack, const char *needle);
	; Locate a substring
	;
	; rdi <- haystack
	; rsi <- needle
	;
	; Return: pointer to the beginning of the located substring

asm_strstr:
					; the following two lines are equivalent to ENTER
	push rbp			; save frame pointer
	mov rbp, rsp			; create new frame

	push rdx			; save @rdx on the stack

asm_strstr_match:

	push rdi			; save @rdi on the stack
	push rsi			; save @rsi on the stack

asm_strstr_match_loop:

	mov dl, byte [rsi]		; copy the byte at @rsi into @dl

	cmp dl, byte 0h			; compare 0 with @dl
	je asm_strstr_found		; jump to "found" if @dl is equal to 0

	cmp dl, byte [rdi]		; compare the byte at @rdi with @dl
	jne asm_strstr_continue		; jump to "continue" if @dl is not equal to the byte at @rdi

	inc rdi				; increment @rdi
	inc rsi				; increment @rsi

	jmp asm_strstr_match_loop	; jump to "match_loop" if the byte at @rdi is equal to @dl

asm_strstr_found:

	pop rsi				; restore @rsi from the stack
	pop rax				; restore @rdi from the stack

	jmp asm_strstr_end		; jump to "end"

asm_strstr_continue:

	pop rsi				; restore @rsi from the stack
	pop rdi				; restore @rdi from the stack

asm_strstr_loop:

	mov dl, byte [rdi]		; copy the byte at @rdi into @dl

	cmp dl, byte 0h			; compare 0 with @dl
	je asm_strstr_none		; jump to "end" if @dl is equal to 0

	cmp dl, byte [rsi]		; compare the byte at @rsi with @dl
	je asm_strstr_match		; jump to "match" if @dl is equal to the byte at @rsi

	inc rdi				; increment @rdi

	jmp asm_strstr_loop		; jump to the beginning of the loop

asm_strstr_none:

	mov rax, 0h			; copy 0 into @rdi

asm_strstr_end:

	pop rdx				; restore @rdx from the stack

					; the following two lines are equivalent to LEAVE
	mov rsp, rbp			; restore stack pointer
	pop rbp				; restore frame pointer

	ret				; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
