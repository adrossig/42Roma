# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arossign <arossign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 10:53:37 by adrossig          #+#    #+#              #
#    Updated: 2022/01/24 12:57:22 by arossign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

LIBFT = ./libft
LIBFT_PATH = $(LIBFT)/libft.a

CC = gcc
CFLAGS =  -Wall -Werror -Wextra -g -g3 -I$(INC) -I$(LIBFT)
LDFLAGS = -L$(LIBFT) -lft
INC = ./includes
SRC = src/
OBJ = obj

PS_FILES := instructions/instruction.c instructions/rotate.c \
			sort/insertion_sort.c sort/magic.c sort/sort.c \
			utils.c main.c

PS_SRC = $(addprefix $(SRC)push_swap/, $(PS_FILES))
PS_OBJ = $(PS_SRC:.c=.o)

SD_FILES := instructions/part1.c instructions/part2.c instructions/part3.c \
						operation.c parsing.c utils.c

SD_SRC = $(addprefix $(SRC)shared/, $(SD_FILES))
SD_OBJ = $(SD_SRC:.c=.o)

CK_FILES := main.c
CK_SRC = $(addprefix $(SRC)checker/, $(CK_FILES))
CK_OBJ = $(CK_SRC:.c=.o)

all: $(NAME) $(CHECKER)

$(NAME): $(LIBFT_PATH) $(PS_OBJ) $(SD_OBJ)
	@$(CC) $(PS_OBJ) $(SD_OBJ) $(CFLAGS) $(LDFLAGS) -o $@

$(LIBFT_PATH):
	@make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(CHECKER): $(LIBFT_PATH) $(CK_OBJ) $(SD_OBJ)
	@$(CC) $(CK_OBJ) $(SD_OBJ) $(CFLAGS) $(LDFLAGS) -o $@

clean:
	@rm -f $(PS_OBJ) $(SD_OBJ) $(CK_OBJ)
	@make -C $(LIBFT) fclean

fclean: clean
	@rm -f $(NAME) $(CHECKER)

bonus: all

re:
	@make fclean
	@make all
