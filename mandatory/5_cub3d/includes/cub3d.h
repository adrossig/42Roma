/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:59:13 by adrossig          #+#    #+#             */
/*   Updated: 2022/01/12 15:06:54 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/minilibx/mlx.h"
# include "../libs/libft/includes/libft.h"
# include <math.h>

# define INT_MAX 2147483647
# define PI 3.1416
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define RIGHT_ARROW_KEY 124
# define LEFT_ARROW_KEY 123
# define ESC_KEY 53
# define NORTH 4.71
# define SOUTH 1.57
# define EAST 0
# define WEST PI
# define HORZ 0
# define VERT 1
# define FALSE 0
# define TRUE 1
# define WALL_2D_COLOR 0x4d4d33
# define RAYS_2D_COLOR 0xffff66
# define FOV 1.1
# define WALL_WIDTH 1
# define MOVE_SPEED 25
# define ROTAT_SPEED 0.10
# define TILE_SIZE 64
# define OFFSET 8

typedef enum	e_playerface
{
	ray_up,
	ray_down,
	ray_left,
	ray_right
}				t_playerface;

typedef enum	e_text
{
	north,
	south,
	east,
	west,
	sprite
}				t_text;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_data;

typedef struct	s_point {
	double		x;
	double		y;
	int			color;
}				t_point;

typedef struct	s_map {
	char		**map_grid;
	int			width;
	int			height;
	int			max_w;
	int			max_h;
	int			n_column;
	int			n_row;
	t_point		*init_posit;
	double		rotation_angle;
	int			num_rays;
	int			color_ceiling;
	int			color_floor;
	char		**path;
	int			n_sprites;
	t_point		**sprite_posit;
}				t_map;

typedef struct	s_player {
	t_point		*posit;
	int			turn_direction;
	int			walk_direction;
	double		rotation_angle;
	int			move_speed;
	double		rotation_speed;
	double		dist_proj_plane;
}				t_player;

typedef struct	s_ray {
	t_point		*collision;
	double		dist_wall;
	double		ray_angle;
	int			coord;
}				t_ray;

typedef struct	s_tex {
	t_data		*data;
	int			width;
	int			height;
}				t_tex;

typedef struct	s_sprite
{
	t_point		*posit;
	double		angle;
	double		angle_dif;
	double		dist;
	int			height;
	int			width;
}				t_sprite;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_data		*data;
	t_map		*map;
	t_point		*point;
	t_player	*player;
	t_ray		**ray;
	t_tex		**tex;
	t_sprite	**sprite;
}				t_vars;

/*
** validate and parse input functions
*/

int				check_args(int argc, char **argv);
int				read_file(char *file, t_map *map);
int				is_identifier(char *line);
int				get_map_info(t_map *map, char *line, int *row, int *ismap);
int				validate_map(t_map *map);
int				get_identifier(t_map *map, char *line);

/*
** error functions
*/

int				ft_error(t_map *map, char *str);
int				ft_path_error(t_vars *vars);
int				ft_arg_error(char *str);

/*
** geometry and auxiliar functions
*/

void			ft_rectangle(t_data *img, t_point point, int width, int height);
void			ft_line(t_data *img, int *p0, int *p1, int color);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
double			ft_normalize_angle(double angle);
double			dist_btw_points(double x0, double y0, double x1, double y1);
int				ft_c_is_in(char c, char *str);
void			**allocate_dynamic(void **buffer, int size, int m);

/*
**  game functions
*/

int				init_game(t_vars *vars, int argc);
int				move_player_press(int keycode, t_vars *vars);
void			put_game(t_vars *vars);
int				update_frame(t_vars *vars);
int				clean_before_close(t_vars *vars);
int				close_program(void);

/*
** setup, create and assign variables
*/

int				create_n_check(t_vars *vars);
t_point			*create_point(int x, int y, int color);
t_data			*create_image(void *mlx_ptr, t_map *map);
void			assign_point(t_point *point, int x, int y, int color);
t_ray			**allocate_ray(t_vars *vars);

/*
** render 2d and 3d functions
*/

int				is_wall(t_map *map, int x, int y, char identf);
int				is_end_window(t_map *map, double x, double y);
void			put_3dmap(t_vars *vars);
void			put_sprites(t_vars *vars);
int				get_texture_color(t_tex *tex, int x, int y);

/*
** raycast calculation
*/

int				ray_facing(double angle, int way);
int				**ft_raycast(t_vars *vars);
void			cast_ray(t_vars *vars, double ray_angle, int coord,
				t_point *next);

/*
** free pointer functions
*/

void			check_n_free(void *ptr);
void			free_tex(void *mlx, t_tex **tex);
void			free_rays(t_vars *vars);
void			free_sprite(t_vars *vars);
void			free_buffer(void **buffer, int n_arrays);
int				free_map(t_map *map);

/*
** convert to bmp function
*/

int				save_bmp_file(t_vars *vars);

/*
** Utils functions
*/

char			*ft_strjoin_n_free(char *s1, char *s2);
void			*ft_calloc_char(size_t count, char c);

#endif
