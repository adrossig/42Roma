section	.text
	global ft_write
	extern __errno_location

ft_write:
	xor rax, rax ; initialize rax (i.e. the return value) at 0
	mov rax, 1 ; rax receives the value 1
	syscall ; make a system call on 1 (=write)
	cmp rax, 0 ; chek if the system call succeeded
	jl error ; if not, jump to the error label
	ret

error:
	neg rax
	mov rdi, rax
	call __errno_location ; call the errno function
	mov [rax], rdi
	mov rax, -1
	ret
