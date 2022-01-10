C = gcc

NAME		= libftprintf.a
LIBFT		= libs/libft
LIBFT_LIB	= libft.a

SRCS		= src/ft_printf.c src/ft_handling.c src/ft_parsing.c src/init.c \
				src/utils.c src/print/ft_char.c src/print/ft_flags.c \
				src/print/ft_hexa.c src/print/ft_int.c src/print/ft_percent.c \
				src/print/ft_pointer.c src/print/ft_string.c src/print/ft_uint.c \
				src/print/ft_width.c

OBJS		= $(SRCS:.c=.o)
INCS		= ./includes/
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus .c.o
