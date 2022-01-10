#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "./key_linux.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HIGHT 600

typedef struct s_fractol
{
	unsigned char	*str;
	char			*name;
	void			*ptr;
	void			*win;
	void			*img;
	double			x;
	double			y;
	double			x_x;
	double			y_y;
	double			x_o;
	double			y_o;
	double			xtemp;
	double			ytemp;
	double			start_x;
	double			end_x;
	double			start_y;
	double			end_y;
	int				itier;
	int				size_l;
	int				bpp;
	int				endian;
	int				index;
	int				zoom;
	int				stop;
	int				max;
	int				color;
}	t_fractol;

int		ft_strcmp(char *str1, char *str2);
void	set_color(t_fractol *fractol, int color);
double	ft_abs(double x);
void	map(t_fractol *fractol);
void	itier_loop(t_fractol *fractol);
void	menu(t_fractol *fractol);
void	string2_put(t_fractol *fractol);
void	init(t_fractol *fractol, char *str);
void	init_x_y(t_fractol *fractol);
void	check_arg(t_fractol *fractol);
void	julia(t_fractol *fractol);
void	mandelbrot(t_fractol *fractol);
int		mouse_move(int x, int y, t_fractol *fractol);
void	zoom(t_fractol *fractol, double x, double y, double zoom);
void	ft_mlx_hook(t_fractol *fractol);
int		mouse_press(int button, int x, int y, t_fractol *fractol);
int		keypress(int keycode, t_fractol *fractol);
int		keypress2(int keycode, t_fractol *fractol);
int		keypress3(int keycode, t_fractol *fractol);
void	keypress4(int keycode, t_fractol *fractol);
void	destroy_exit(t_fractol *fractol);
void	simple_zoom1(t_fractol *fractol);
void	simple_zoom2(t_fractol *fractol);

#endif
