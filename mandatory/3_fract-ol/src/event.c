/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:12:02 by arossign          #+#    #+#             */
/*   Updated: 2022/01/12 13:12:03 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_press(int button, int x, int y, t_fractol *fractol)
{
	if (button == 5 && fractol->stop == 1)
		zoom(fractol, (double)x, (double)y, 1 / 0.5);
	else if (button == 4 && fractol->stop == 1)
		zoom(fractol, (double)x, (double)y, 0.5);
	check_arg(fractol);
	return (1);
}

int	keypress(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESCAPE)
	{
		destroy_exit(fractol);
		exit(0);
	}
	else if (keycode == KEY_PAD_DIVIDE)
	{
		if (fractol->max >= 10)
			fractol->max -= 10;
		check_arg(fractol);
	}
	else
		keypress2(keycode, fractol);
	return (1);
}

int	keypress2(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_LEFT)
	{
		fractol->start_x = fractol->start_x + 0.037;
		fractol->end_x = fractol->end_x + 0.037;
		check_arg(fractol);
	}
	else if (keycode == KEY_RIGHT)
	{
		fractol->start_x = fractol->start_x - 0.037;
		fractol->end_x = fractol->end_x - 0.037;
		check_arg(fractol);
	}
	else if (keycode == KEY_DOWN)
	{
		fractol->start_y = fractol->start_y - 0.037;
		fractol->end_y = fractol->end_y - 0.037;
		check_arg(fractol);
	}
	else
		keypress3(keycode, fractol);
	return (1);
}

int	keypress3(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_UP)
	{
		fractol->start_y = fractol->start_y + 0.037;
		fractol->end_y = fractol->end_y + 0.037;
		check_arg(fractol);
	}
	else if (keycode == KEY_PAD_MULTIPLY)
	{
		fractol->max += 10;
		check_arg(fractol);
	}
	else
		keypress4(keycode, fractol);
	return (1);
}

void	keypress4(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ONE)
	{
		fractol->name = "Julia";
		init(fractol, fractol->name);
		check_arg(fractol);
	}
	else if (keycode == KEY_TWO)
	{
		fractol->name = "Mandelbrot";
		init(fractol, fractol->name);
		check_arg(fractol);
	}
	else if (keycode == KEY_THREE)
	{
		fractol->name = "Burningship";
		init(fractol, fractol->name);
		check_arg(fractol);
	}
	else if (keycode == KEY_C)
	{
		fractol->color += 15;
		check_arg(fractol);
	}
}
