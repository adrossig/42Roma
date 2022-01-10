section .text
	extern malloc
	global ft_list_push_front

ft_list_push_front:
	push rsp ; save the content of rsp (i.e. a general register = stack pointer) by putting it in the pile
	push rdi ; save begin_list (rdi can now be used : set at 0)
	push rsi ; save data (rsi can now be used : set at 0)

	mov rdi, 16 ; add 16 bits to rdi (content = 1B, pointer to the next element of the list = 1B)
	xor rax, rax ; initialize rax at 0
	call malloc ; call the malloc function
	pop rsi ; get the content of the pile (= stack) back in the register rsi
	pop rdi ; get the content of the pile (= stack) back in the register rdi
	cmp rax, 0 ; compare rax (the return of the malloc function) to 0
	jz return ; if malloc failed, jump to the return label

	mov [rax], rsi ; new.data = data
	mov rcx, [rdi]
	mov [rax + 8], rcx ; new.next = *begin
	mov [rdi], rax ; *begin = new

return:
	pop rsp ; get the content of the pile (= stack) back in the register rsp
	ret