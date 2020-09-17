BITS 64
	global asm_strcmp	; export 'asm_strlen' function

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

	mov rdx, 0h	; copy 0 into @rdx

asm_strcmp_loop:

	mov dl,	[rdi]		; copy the byte at @rdi into @dl
	mov dh,	[rsi]		; copy the byte at @rsi into @dh
	cmp dl,	dh		; compare @dl with @dh
	jne asm_strcmp_nomatch	; jump to diff if @dl is not equal to @dh
	cmp dl,	0h		; compare @dl with 0
	je asm_strcmp_match	; jump to end if @dl is equal to 0
	inc rdi			; increment @rdi
	inc rsi			; increment @rsi
	jmp asm_strcmp_loop	; jump to the start of the loop

asm_strcmp_less:

	mov eax, -1h	; return the value stored in @edx

	jmp asm_strcmp_end

asm_strcmp_more:

	mov eax, 1h		; return the value stored in @edx

	jmp asm_strcmp_end

asm_strcmp_match:

	mov eax, 0h		; return the value stored in @edx

	jmp asm_strcmp_end
	
asm_strcmp_nomatch:
	
	cmp dl,	0h		; compare @dl with 0
	je asm_strcmp_less	; jump to less if @dl is equal to 0
	cmp dh,	0h		; compare @dh with 0
	je asm_strcmp_more	; jump to more if @dh is equal to 0

	sub dl, dh		; subtract @dh from @dl

	mov al, dl		; return the value stored in @edx

	cbw			; convert @al to @ax
	cwd			; convert @ax to @eax

	jmp asm_strcmp_end	; jump to end

asm_strcmp_end:

	pop rdx		; restore @rdx

			; the following two lines are equivalent to LEAVE
	mov rsp, rbp	; restore stack pointer
	pop rbp		; restore frame pointer

	ret		; pop @rip
