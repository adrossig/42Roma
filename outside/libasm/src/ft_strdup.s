section .text
	extern malloc
	extern ft_strlen
	extern ft_strcpy
	global ft_strdup

ft_strdup:
	push rdi ; push the value rdi to the stack
	call ft_strlen ; call the function ft_strlen()
	inc rax ; increment rax
	mov rdi, rax ; rdi recieved the value of rax

	call malloc ; call malloc
	pop rdi ; restore original rdi (remove from the stack)

	mov rsi, rdi ; 2nd = str
	mov rdi, rax ; 1st = ptr
	call ft_strcpy ; ft_strcpy(ptr, str)
	ret
