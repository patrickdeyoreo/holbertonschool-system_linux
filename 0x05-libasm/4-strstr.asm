BITS 64
	global asm_strstr		; export 'asm_strstr' function

	section .text

	; char *asm_strstr(const char *haystack, const char *needle);
	; Locate a substring
	;
	; rdi <- haystack
	; rsi <- needle
	;
	; Return: pointer to the beginning of the located substring

asm_strstr:

	push rbp			; save frame pointer
	mov rbp, rsp			; create new frame

	xor rax, rax			; zero-initialize @rax

	sub rsp, 16			; increase the size of the stack by 16 bytes

asm_strstr_match:

	mov [rsp - 8], rdi		; save @haystack on the stack
	mov [rsp], rsi			; save @needle on the stack

asm_strstr_match_loop:

	mov dl, [rsi]			; copy the byte at @rsi into @dl

	cmp dl, 0			; compare 0 with @dl
	je asm_strstr_match_found	; jump to "match_found" if @dl is equal to 0

	cmp dl, [rdi]			; compare the byte at @rdi with @dl
	jne asm_strstr_match_break	; jump to "match_break" if @dl is not equal to the byte at @rdi

	inc rdi				; increment @rdi
	inc rsi				; increment @rsi

	jmp asm_strstr_match_loop	; jump to "match_loop" if the byte at @rdi is equal to @dl

asm_strstr_match_found:

	mov rax, [rsp - 8]		; return @rdi from the stack

	jmp asm_strstr_end		; jump to "end"

asm_strstr_match_break:

	mov rdi, [rsp - 8]		; restore @rdi from the stack
	mov rsi, [rsp]			; restore @rsi from the stack

	cmp byte [rdi], 0		; compare 0 with the byte at @rdi
	jne asm_strstr_continue		; jump to "continue"

	jmp asm_strstr_end		; jump to "end"

asm_strstr_loop:

	mov dl, [rdi]			; copy the byte at @rdi into @dl

	cmp dl, [rsi]			; compare the byte at @rsi with @dl
	je asm_strstr_match		; jump to "match" if @dl is equal to the byte at @rsi

	cmp dl, 0			; compare 0 with @dl
	je asm_strstr_end		; jump to "end" if @dl is equal to 0

asm_strstr_continue:

	inc rdi				; increment @rdi

	jmp asm_strstr_loop		; jump to the beginning of the loop

asm_strstr_end:

	add rsp, 16			; decrease the size of the stack by 16 bytes

	mov rsp, rbp			; restore stack pointer
	pop rbp				; restore frame pointer

	ret				; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
