section .text
	global	ft_strcmp
	extern	ft_strlen

ft_strcmp:
	xor rcx, rcx ; initialize rcx (i.e. the cursor) at 0 (because bytes are =)
	xor rax, rax ; initialize rax (i.e. the return value) at 0 (//)

comp:
	xor al, al ; initialize	al (the low part of the ax register)
	sub al, byte[rsi + rcx]	; al = al - byte[rsi + rcx]
	add al, byte[rdi + rcx]	; al = al + byte[rdi + rcx]
	jz incr ; if al equals , jump to the incr label
	movsx	rax, al ; if not, al is copied in rax (even though it is < to the latest:
					; remaning bytes in rax are filled with the extension of the signs)
	ret ; return rax

incr:
	inc rcx ; increment rcx
	cmp byte[rdi + rcx], 0 ; check if rdi[rcx] == '\0'
	jnz comp ; if not equal, jump to comp label
	cmp byte[rsi + rcx], 0 ; else check if rsi[rcx] == '\0'
	jnz comp ; if not equal, jump to comp label
	mov rax, 0 ; else rax receives the value 0
	ret
