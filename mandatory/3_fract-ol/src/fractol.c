/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:12:14 by arossign          #+#    #+#             */
/*   Updated: 2022/01/12 13:12:15 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_fractol *fractol)
{
	mlx_clear_window(fractol->ptr, fractol->win);
	fractol->y_y = 0;
	while (fractol->y_y < WIDTH)
	{
		fractol->x_x = 0;
		while (fractol->x_x < HIGHT)
		{
			fractol->itier = 0;
			init_x_y(fractol);
			itier_loop(fractol);
			if (fractol->itier == fractol->max)
				set_color(fractol, 0);
			else
				set_color(fractol, 1);
			fractol->x_x++;
		}
		fractol->y_y++;
	}
	ft_mlx_hook(fractol);
}

void	mandelbrot(t_fractol *fractol)
{
	mlx_clear_window(fractol->ptr, fractol->win);
	fractol->y_y = 0;
	while (fractol->y_y < WIDTH)
	{
		fractol->x_x = 0;
		while (fractol->x_x < HIGHT)
		{
			fractol->itier = 0;
			map(fractol);
			itier_loop(fractol);
			if (fractol->itier == fractol->max)
				set_color(fractol, 0);
			else
				set_color(fractol, 1);
			fractol->x_x++;
		}
		fractol->y_y++;
	}
	fractol->stop = 1;
	ft_mlx_hook(fractol);
}

int	mouse_move(int x, int y, t_fractol *fractol)
{
	if (x < 600 && y < 600 && fractol->stop == 0 && \
		ft_strcmp(fractol->name, "Julia") == 0)
	{
		fractol->x_o = (((double)x / 600) * 4) - 2;
		fractol->y_o = ((((double)y * -1) / 600) * 4) + 2;
		check_arg(fractol);
	}
	return (1);
}

void	zoom(t_fractol *fractol, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((x / WIDTH) * (fractol->end_x - fractol->start_x)) + fractol->start_x;
	yy = ((y / HIGHT) * (fractol->end_y - fractol->start_y)) + fractol->start_y;
	fractol->start_x = xx + ((fractol->start_x - xx) * zoom);
	fractol->start_y = yy + ((fractol->start_y - yy) * zoom);
	fractol->end_x = xx + ((fractol->end_x - xx) * zoom);
	fractol->end_y = yy + ((fractol->end_y - xx) * zoom);
	if (fractol->max <= 120)
		fractol->max += 2;
}

void	ft_mlx_hook(t_fractol *fractol)
{
	menu(fractol);
	mlx_mouse_hook(fractol->win, mouse_press, fractol);
	mlx_hook(fractol->win, 6, (1L << 6), mouse_move, fractol);
	mlx_hook(fractol->win, 2, 1, keypress, fractol);
	mlx_loop(fractol->ptr);
}
