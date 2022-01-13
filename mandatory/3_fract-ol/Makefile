NAME = fractol

CC = clang

MLX = $(MLX_DIR)/libmlx.a
MLX_DIR = minilibx

HEADER = -I./includes -I./$(MLX_DIR)
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
#LFLAGS = -lbsd -lm -lX11 -lXext -L ./$(MLX_DIR) -lmlx
LFLAGS = -L ./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS = src/event.c \
		src/event2.c \
		src/fractol.c \
		src/utils.c \
		src/main.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX)
	@$(CC) $(OBJS) $(HEADER) $(CFLAGS) $(LFLAGS) -o $@

clean:
	@rm -fr $(OBJS)

fclean: clean
	@rm -fr $(NAME)

bonus: fclean all

re: fclean all
