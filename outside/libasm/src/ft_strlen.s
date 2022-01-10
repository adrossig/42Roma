section	.text
	global	ft_strlen

ft_strlen:
	mov rcx, 0 ; initialize rcx (i.e. the cursor) at 0
	mov rax, 0 ; initialize rax (i.e. the return value) at 0
	jmp comp ; jump to the comp label

incr:
	inc rcx; increment rcx

comp:
	cmp byte[rdi + rcx], 0	; compare the byte at str[rcx] to 0
	jne incr ; if not equal, jump to the incr label
	mov rax, rcx ; if equal, rax get the value of rcx
	ret ; return rax
