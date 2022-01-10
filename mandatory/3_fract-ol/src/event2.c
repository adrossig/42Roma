#include "../includes/fractol.h"

void	simple_zoom1(t_fractol *fractol)
{
	if (fractol->start_x < 0 && fractol->start_y < 0 \
		&& fractol->end_x > 0 && fractol->end_y > 0)
	{
		fractol->start_x = fractol->start_x + 0.015;
		fractol->start_y = fractol->start_y + 0.015;
		fractol->end_x = fractol->end_x - 0.015;
		fractol->end_y = fractol->end_y - 0.015;
	}
}

void	simple_zoom2(t_fractol *fractol)
{
	fractol->start_x = fractol->start_x - 0.040;
	fractol->start_y = fractol->start_y - 0.040;
	fractol->end_x = fractol->end_x + 0.040;
	fractol->end_y = fractol->end_y + 0.040;
}

void	init_x_y(t_fractol *fractol)
{
	fractol->x = ((fractol->x_x / (double)WIDTH) * \
		(fractol->end_x - fractol->start_x)) + fractol->start_x;
	fractol->y = ((fractol->y_y / (double)HIGHT) * \
		(fractol->end_y - fractol->start_y)) + fractol->start_y;
}

void	string2_put(t_fractol *fractol)
{
	mlx_string_put(fractol->ptr, fractol->win, 650, 50, 0xFFFFFF,
		"    ZOOM    ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 70, 0xf7b079, \
		"    Scroll UP | Scroll Down    ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 500, 0xFFFFFF,
		"    Iteration    ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 520, 0xf7b079,
		"    / | *    ");
}

void	destroy_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->ptr, fractol->img);
	mlx_destroy_window(fractol->ptr, fractol->win);
	free(fractol->ptr);
}
