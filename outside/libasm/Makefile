# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 10:23:27 by adrossig          #+#    #+#              #
#    Updated: 2021/05/04 14:46:16 by adrossig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

NA = nasm

NFLAGS = -f elf64

SRC := src/ft_read.s \
	src/ft_write.s \
	src/ft_strcmp.s \
	src/ft_strlen.s \
	src/ft_strcpy.s \
	src/ft_strdup.s \

B_SRC := src/ft_atoi_base_bonus.s \
		src/ft_list_size_bonus.s \
		src/ft_list_push_front_bonus.s \
		src/ft_list_sort_bonus.s \
		src/ft_list_remove_if_bonus.s

OBJ := $(SRC:.s=.o)
OBONUS := $(SRC:%.s=%.o) $(B_SRC:%.s=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;33mUpdating library..."
	ar rcs $(NAME) $^
	ranlib $(NAME)
	@echo "\033[0m"

%.o: %.s
	@echo "\033[0;32mGenerating binary..."
	$(NA) $(NFLAGS) $<
	@echo "\033[0m"

bonus: $(OBONUS)
	@echo "$(C_LYLW)➜ [$(NAME)] Updating library with bonus files...$(C_END)"
	@echo "\033[1A$(T_CLR)$(C_LGRN)➜ [$(NAME)] Objects have been compiled successfully!$(C_END)"
	@ar rcs $(NAME) $^
	@ranlib $(NAME)
	@echo "$(C_LGRN)➜ [$(NAME)] Library has been Compiled Successfully!$(C_END)"

clean:
	@echo "\033[0;31mCleaning..."
	rm -f $(OBJ) $(OBONUS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving library..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: clean fclean re
