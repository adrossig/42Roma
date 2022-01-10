section	.text
	global	ft_atoi_base

ft_atoi_base: 
	xor rax, rax ; initialize rax(i.e. the return value) at 0
	xor rbx, rbx ; initialize rbx(i.e. the sign) at 0
	xor r12, r12 ; initialize r12(i.e. the base length) at 0 (i = 0)
	jmp base_loop

base_incr:
	inc r12 ; increment r12 (i++)

base_loop:
	cmp byte[rsi + r12], 0 ; check if rsi[r12] == '\0'
	jz base_end ; if equal, jump to base_end label
	mov r8, r12 ; else r8 receives the value of r12 (j = i)

check_incr:
	inc r8 ; increment r8 (j++)

check_loop:
	cmp byte[rsi + r8], 0 ; chek if base[r8] == '\0'
	jz base_check ; if equal, jump to the base_check label
	mov r9b, [rsi + r8]
	cmp byte[rsi + r12], r9b ; base[base_length] == base[j]
	je set_rax ; if equal, jump to the set_rax label
	jmp check_incr ; else, jump to the check_incr label

base_check:
	cmp byte[rsi + r12], 32 ; chek if base[base_length] == ' '
	je set_rax
	cmp byte[rsi + r12], 43 ; chek if base[base_length] == '+'
	je set_rax
	cmp byte[rsi + r12], 45 ; chek if base[base_length] == '-'
	je set_rax
	cmp byte[rsi + r12], 9 ; chek if base[base_length] == '\t'
	je set_rax
	cmp byte[rsi + r12], 10 ; chek if base[base_length] == '\n'
	je set_rax
	cmp byte[rsi + r12], 13 ; chek if base[base_length] == '\r'
	je set_rax
	cmp byte[rsi + r12], 11 ; chek if base[base_length] == '\v'
	je set_rax
	cmp byte[rsi + r12], 12 ; chek if base[base_length] == '\f'
	je set_rax
	jmp base_incr

base_end:
	cmp r12, 1 ; check if base_length <= 1 (if so, it means the base is not valid)
	jle set_rax ; if lower or equal, jump to the set_rax label
	xor r8, r8 ; else initialize r8 at 0 (i = 0)
	jmp skip_white ; jump to the skip_white label

skip_incr:
	inc r8 ; i++

skip_white:
	cmp byte[rdi + r8], 32 ; check if str[i] == ' '
	je skip_incr
	cmp byte[rdi + r8], 9 ; check if str[i] == '\t'
	je skip_incr
	cmp byte[rdi + r8], 10 ; check if str[i] == '\n'
	je skip_incr
	cmp byte[rdi + r8], 13 ; check if str[i] == '\r'
	je skip_incr
	cmp byte[rdi + r8], 11 ; check if str[i] == '\v'
	je skip_incr
	cmp byte[rdi + r8], 12 ; check if str[i] == '\f'
	je skip_incr
	jmp check_sign

is_negative:
	xor bl, 0x00000001

is_positive:
	inc r8

check_sign:
	cmp byte[rdi + r8], 45 ; check if str[i] == '-'
	je is_negative ; if equal, jump to the is_negative label
	cmp byte[rdi + r8], 43 ; else check if str[i] == '+'
	je is_positive ; if equal, jump to the is_positive label
	jmp atoi_loop ; else jump to the atoi_loop label

atoi_incr:
	inc r8 ; increment r8 (i++)

atoi_loop:
	cmp byte[rdi + r8], 0 ; str[i] == '\0'
	je set_rax ; if equal jump to the set_rax label
	xor r9, r9 ; else initialize r9 at 0
	jmp atoi_index

index_incr:
	inc r9 ; increment r9 (j++)

atoi_index:
	mov r10b, byte[rsi + r9] ; r10b (8 "lower" bits register) receives the value of the byte at rsi[r9]
	cmp r10b, 0 ; check if r10b == '\0' (base[j] == 0)
	je set_rax
	cmp byte[rdi + r8], r10b ; else check if rdi[r8] == r10b (base[j] == str[i])
	jne index_incr ; if not equal, jump to the atoi_idx_inc label

add_to_total:
	mul r12 ; total *= base_length
	add rax, r9
	jmp atoi_incr

set_rax:
	mov rax, rax ; ret = total
	cmp rbx, 0 ; check if rbx == 0 (if so, the sign is positive)
	jz return ; if equal, jump to the return label
	neg rax ; else ret = -ret

return:
	ret