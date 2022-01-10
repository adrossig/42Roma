section .text
	global ft_list_size
	
ft_list_size:
	mov rsi, rdi ; rsi receives the value of rdi
	xor rax, rax ; initialize rax at 0
	jmp count

incr:
	inc rax

count:
	cmp rdi, 0 ; check if begin_list is a null pointer
	jnz move ; jump to the move label if not
	mov rdi, rsi
	ret

move:
	mov rdi, [rdi + 8] ; begin = begin.next (to go through the list)
	jmp incr