# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 11:29:00 by adrossig          #+#    #+#              #
#    Updated: 2021/11/04 11:29:01 by adrossig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = ./includes/

CC = gcc

CFLAGS = -Werror -Wall -Wextra -g -I$(HEADER) -pthread

SRCS = src/main.c \
		src/activity.c \
		src/thread.c \
		src/init.c \
		src/parsing.c \
		src/utils_philo.c \
		src/utils_libft.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all
