section	.text
	global	ft_strcpy

ft_strcpy:
	xor rcx, rcx ; initialize rcx (i.e. the cursor) at 0 (because bytes are equal)
	xor rax, rax ; initialize rax (i.e. the return value) at 0 (//)

copy:
	mov al, byte[rsi + rcx] ; al receives the value of the byte at the source address rsi + rcx
	mov byte[rdi + rcx], al ; the byte at the destination adress rdi + rcx receives the value of al

incr:
	inc rcx ; increment rcx

comp:
	cmp byte[rsi + rcx], 0 ; compare the byte at str[rcx] to 0
	jne copy ; if not equal, jump to the copy label
	mov rax, rdi ; if equal, rax get the value of rdi
	ret ; return
