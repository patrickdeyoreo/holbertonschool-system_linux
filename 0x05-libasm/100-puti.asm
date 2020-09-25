BITS 64
	global asm_puti		; export 'asm_puti' function

	extern asm_putc		; import 'asm_putc' function

	section .text

	; size_t asm_puti(int n);
	; Print a signed integer on standard output
	;
	; rdi <- n
	;
	; Return: the number of bytes written

asm_puti:

	push rbp		; save frame pointer
	mov rbp, rsp		; create new frame

	sub rsp, 20		; increase the size of the stack by 20 bytes

asm_puti_rax:

	mov qword [rsp - 12], 0 ; save return value on the stack

asm_puti_n:

	mov [rsp - 8], edi	; copy @n onto the stack

asm_puti_sign:

	mov dword [rsp - 4], 1	; copy 1 onto the stack

	cmp edi, 0		; compare 0 with @n

	jge asm_puti_char	; jump to "char" if @n is non-negative

	neg dword [rsp - 4]	; flip the sign

asm_puti_char:

	mov dword [rsp], 0x30	; copy '0' onto the stack

	xor edx, edx		; clear @edx

	mov eax, edi		; copy @n into @eax

	mov edi, 10		; copy 10 into @edi

	idiv edi		; divide @eax by 10

	mov eax, edx		; copy the remainder into @eax

	imul dword [rsp - 4]	; multiply the remainder by the sign

	add [rsp], eax		; add the result to the dword at @rsp

asm_puti_loop:

	cmp dword [rsp - 8], 0	; compare 0 with @n

	jge asm_puti_loop_div	; jump to "loop_div" if @n is non-negative

	mov edi, 0x2D		; copy '-' into @edi

	call asm_putc		; call putc with '-'

	inc qword [rsp - 12]	; increment the return value on the stack

asm_puti_loop_div:

	xor edx, edx		; clear @edx

	mov eax, [rsp - 8]	; copy @n into @eax

	mov edi, 10		; copy 10 into @edi

	idiv edi		; divide @eax by 10

	cmp eax, 0		; compare 0 with the quotient

	je asm_puti_loop_putc	; jump to "loop_putc" if the quotient is 0

	imul dword [rsp - 4]	; multiply the quotient by the sign

	mov edi, eax		; copy the result into @edi

	call asm_puti		; call 'asm_puti' recursively

	add [rsp - 12], rax	; add to the return value on the stack

asm_puti_loop_putc:

	mov edi, [rsp]		; copy the dword at @rsp into @edi

	call asm_putc		; call putc with the dword at @rsp

	inc qword [rsp - 12]	; save the return value on the stack

asm_puti_end:

	mov rax, [rsp - 12]	; return the total number of bytes written 

	add rsp, 20		; decrease the size of the stack by 20 bytes

	mov rsp, rbp		; restore stack pointer
	pop rbp			; restore frame pointer

	ret			; pop @rip

; vi: set noet ft=nasm sts=0 sw=8 ts=8 :
