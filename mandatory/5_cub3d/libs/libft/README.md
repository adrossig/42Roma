# Libft

### :bulb: Evaluation Log
1. 2019-12-16 : OK
	- **105 score** (mandatory 100 + bonus 5)
---

### :bulb: Objective
- to code a C library regrouping functions.
- the functions will be allowed to use in all other projects.
---

### :bulb: List of Functions
1. Mandatory Part
	- ***memory*** : 
	[`memset`](./src/mem/ft_memset.c) [`bzero`](./src/mem/ft_bzero.c) [`memcpy`](./src/mem/ft_memcpy.c) [`memccpy`](./src/mem/ft_memccpy.c) [`memmove`](./src/mem/ft_memmove.c) [`memchr`](./src/mem/ft_memchr.c) [`memcmp`](./src/mem/ft_memcmp.c) [`calloc`](./src/mem/ft_calloc.c)
	- ***string(lib)*** :
	[`strlen`](./src/str/ft_strlen.c) [`strlcpy`](./src/str/ft_strlcpy.c) [`strlcat`](./src/str/ft_strlcat.c) [`strchr`](./src/str/ft_strchr.c) [`strrchr`](./src/str/ft_strrchr.c) [`strnstr`](./src/str/ft_strnstr.c) [`strncmp`](./src/str/ft_strncmp.c) [`atoi`](./src/str/ft_atoi.c) [`strdup`](./src/str/ft_strdup.c)
	- ***is_sth, to_sth*** : 
	[`isalpha`](./src/char/ft_isalpha.c) [`isdigit`](./src/char/ft_isdigit.c) [`isalnum`](./src/char/ft_isalnum.c) [`isascii`](./src/char/ft_isascii.c) [`isprint`](./src/char/ft_isprint.c) [`toupper`](./src/char/ft_toupper.c) [`tolower`](./src/char/ft_tolower.c)
	- ***string(non-lib)*** : 
	[`ft_substr`](./src/char/ft_substr.c) [`ft_strjoin`](./src/char/ft_strjoin.c) [`ft_strtrim`](./src/char/ft_strtrim.c) [`ft_split`](./src/char/ft_split.c) [`ft_itoa`](./src/conv/ft_itoa.c) [`ft_strmapi`](./src/char/ft_strmapi.c)
	- ***put_fd*** : 
	[`ft_putchar_fd`](./src/print/ft_putchar_fd.c) [`ft_putstr_fd`](./src/print/ft_putstr_fd.c) [`ft_putendl_fd`](./src/print/ft_putendl_fd.c) [`ft_putnbr_fd`](./src/print/ft_putnbr_fd.c)

2. Bonus Part
	- ***linked_list*** :
	[`ft_lstnew`](./src/lst/ft_lstnew.c) [`ft_lstadd_front`](./src/lst/ft_lstadd_front.c) [`ft_lstsize`](./src/lst/ft_lstsize.c) [`ft_lstlast`](./src/lst/ft_lstlast.c) [`ft_lstadd_back`](./src/lst/ft_lstadd_back.c) [`ft_lstdelone`](./src/lst/ft_lstdelone.c) [`ft_lstclear`](./src/lst/ft_lstclear.c) [`ft_lstiter`](./src/lst/ft_lstiter.c) [`ft_lstmap`](./src/lst/ft_lstmap.c)
---

### :bulb: Useful Links
- __libftest__ by [_jtoty_](https://github.com/jtoty/Libftest)
	```
	git clone https://github.com/jtoty/Libftest.git
	```
- __unit test__ by [_alelievr_](https://github.com/alelievr/libft-unit-test)
	```
	git clone https://github.com/alelievr/libft-unit-test.git
	```
- __war machine__ by [_ska42_](https://github.com/ska42/libft-war-machine)
	```
	git clone https://github.com/ska42/libft-war-machine.git
	```
- __libft_tester__ by [_Lusaka_](https://github.com/Lusaka33/libft_tester)
	```
	git clone https://github.com/Lusaka33/libft_tester.git
	```
