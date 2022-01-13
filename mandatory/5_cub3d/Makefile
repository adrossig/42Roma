NAME = cub3D
LIBFT_DIR =	libs/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = libs/minilibx
MLX = $(MLX_DIR)/libmlx.a

SRCS =		srcs/main.c \
			srcs/geometry_line.c \
			srcs/geometry_rect.c \
			srcs/input_check_args.c \
			srcs/input_read_n_validate.c \
			srcs/input_parse_identif.c \
			srcs/input_parse_map.c \
			srcs/vars_create_1.c \
			srcs/vars_create_2.c \
			srcs/game.c \
			srcs/key_update.c \
			srcs/raycast.c \
			srcs/raycast_intercept.c \
			srcs/render_2d.c \
			srcs/render_3d.c \
			srcs/sprite.c \
			srcs/auxiliar_funct.c \
			srcs/free_info.c \
			srcs/error.c \
			srcs/save_bmp_file.c \
			srcs/utils.c

OBJS =		$(patsubst srcs%.c, .objs%.o, $(SRCS))

CC =		clang
HEAD =		-I./includes -I./$(LIBFT_DIR) -I./$(MLX_DIR)
CFLAGS =	-Wall -Werror -Wextra -g -fsanitize=address -o3
#LFLAGS =	-lbsd -lm -lX11 -lXext \
			-L ./$(LIBFT_DIR) -lft \
			-L ./$(MLX_DIR) -lmlx
LFLAGS = -L ./$(MLX_DIR) -L ./$(LIBFT_DIR) -lft -lmlx -framework OpenGL -framework AppKit
RM =		/bin/rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
		$(CC) $(OBJS) $(HEAD) $(CFLAGS) $(LFLAGS) -o $@

.objs/%.o: srcs/%.c
		mkdir -p .objs
		$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(LIBFT):
		make -C $(LIBFT_DIR)

$(MLX):
		make -C $(MLX_DIR)

clean:
		make clean -C $(LIBFT_DIR)
		make clean -C $(MLX_DIR)
		$(RM) .objs

fclean: clean
		make fclean -C $(LIBFT_DIR)
		$(RM) $(NAME)
		$(RM) *.bmp

re: fclean all

.PONY: all clean fclean re
