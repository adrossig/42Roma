section	.text
	global	ft_list_sort

ft_list_sort:
	push rbx ; save rbx (next)
	push r12 ; save r12 (first)
	cmp rdi, 0 ; check if rdi == NULL
	jz restore ; if equal, jump to the restore label
	mov r12, [rdi] ; else r12 receives the adress of rdi (first = *begin)
	cmp rsi, 0 ; check if rsi == NULL
	jz return ; if equal, jump to the return label
	jmp comp_main ; else jump to the comp_main label

incr_main:
	mov rcx, [rdi]
	mov rbx, [rcx + 8]
	mov [rdi], rbx ; *begin = (*begin)->next

comp_main:
	cmp QWORD [rdi], 0 ; check if the adress of rdi = NULL (*begin == NULL) (!*begin)
	jz return ; if equal, jump to the return label
	mov rcx, [rdi] ; rcx receives the adress of rdi
	mov rbx, [rcx + 8] ; current = (*begin)->next

comp_single:
	cmp rbx, 0 ; !current
	jz incr_main

compare:
	push rdi ; save rdi
	push rsi ; save rsi
	mov rax, rsi
	mov rcx, [rdi]
	mov rdi, [rcx] ; rdi = (*begin)->data
	mov rsi, [rbx] ; rsi = current->data
	call rax ; (*cmp)((*begin)->data, current->data)
	pop rsi
	pop rdi
	cmp rax, 0 ; check if rax > 0
	jg swap ; if superior, jump to the swap label

incr_single:
	mov rcx, [rbx + 8]
	mov rbx, rcx ; current = current.next
	jmp comp_single

swap:
	mov r8, [rdi]
	mov rcx, [r8] ; rcx = (*begin)->data
	mov rax, [rbx] ; rax = current->data
	mov [r8], rax ; (*begin)->data = current->data
	mov [rbx], rcx ; current->data = (*begin)->data
	jmp incr_single

return:
	mov [rdi], r12 ; the adress of rdi receives the value of r12 (*begin = first)

restore:
	pop r12 ; restore r12
	pop rbx ; restore rbx
	ret