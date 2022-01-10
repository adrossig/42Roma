# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrossig <adrossig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 15:54:34 by adrossig          #+#    #+#              #
#    Updated: 2019/11/25 15:54:34 by adrossig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -W -pedantic -g -fsanitize=address
INC = libft.h

T_BLK = \033[5m
T_NRM = \033[25m
T_CLR = \033[K
C_YLW = \033[33m
C_GRN = \033[32m
C_LYLW = \033[93m
C_LGRN = \033[92m
C_LMGN = \033[95m
C_END = \033[0m

CHAR := ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c \
		ft_atoi.c ft_bzero.c ft_itoa.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
		ft_strchr.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_strlen.c ft_strdup.c ft_calloc.c

SRCS_B = ./ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

FILES := $(CHAR)

SRC := $(FILES)
OBJ := $(SRC:%.c=%.o)
OBONUS := $(SRCS_B:%.c=%.o)

NB = $(words $(FILES))
IND = 0
PER = 0

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)
	@$(eval IND=$(shell echo $$(($(IND) + 1))))
	@$(eval PER=$(shell echo $$((($(IND) * 100) / $(NB)))))
	@printf "$(T_CLR)$(C_LYLW)➜ ➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);

$(NAME):
	@echo "$(C_LYLW)➜ [$(NAME)] Compiling objects ... $(C_END)"
	@make $(OBJ)
	@echo "\033[1A$(T_CLR)$(C_LGRN)➜ [$(NAME)] Objects have been compiled successfully ! $(C_END)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(C_LGRN)➜ [$(NAME)] Library has been Compiled Successfully !$(C_END)"

clean:
	@rm -f $(OBJ) $(OBONUS)
	@echo "$(C_LMGN)➜ [$(NAME)] Objects have been cleaned Successfully !$(C_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(C_LMGN)➜ [$(NAME)] Library has been deleted Successfully !$(C_END)"

re: fclean all
	@echo "$(C_LGRN)➜ [$(NAME)] Library has been re-builded\
	 Successfully !$(C_END)"

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) $(INC)

bonus: $(OBONUS)
	ar rc $(NAME) $(OBONUS)
	@echo "$(C_LGRN)➜ [$(OBONUS)] Bonus has been Compiled Successfully !$(C_END)"


.PHONY: clean fclean re
