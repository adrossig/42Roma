/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:12:19 by arossign          #+#    #+#             */
/*   Updated: 2022/01/12 13:12:20 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	string_put(t_fractol *fractol)
{
	mlx_string_put(fractol->ptr, fractol->win, 650, 110, 0xFFFFFF, \
		"    MOVE    ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 140, 0xf7b079, \
		"    Arrow UP | Arrow Down    ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 180, 0xf7b079, \
		"    Arrow Right | Arrow Left    ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 240, 0xFFFFFF, \
		"    Change Fractal    ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 280, 0xf7b079, \
		"    Julia | Button (1)    ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 310, 0xf7b079, \
		"    Mandelbrot | Button (2)    ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 340, 0xf7b079, \
		"    BurningShip | Button (3)    ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 380, 0xFFFFFF, \
		"    Change Color    ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 410, 0xf7b079, \
		"    Button (C)    ");
}

void	menu(t_fractol *fractol)
{
	int	i;
	int	j;

	j = -1;
	while (++j < HIGHT)
	{
		i = 599;
		while (++i < 1000)
		{
			fractol->index = (j * 1000 * 4) + (i * 4);
			fractol->str[fractol->index] = 189;
			fractol->str[fractol->index + 1] = 87;
			fractol->str[fractol->index + 2] = 54;
			fractol->str[fractol->index + 3] = 0;
		}
	}
	mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->img, 0, 0);
	string2_put(fractol);
	string_put(fractol);
}

void	init(t_fractol *fractol, char *str)
{
	fractol->start_x = -2;
	fractol->end_x = 2;
	fractol->start_y = -2;
	fractol->end_y = 2;
	fractol->x_o = -0.4;
	fractol->y_o = 0.6;
	fractol->zoom = 0;
	fractol->stop = 0;
	fractol->max = 40;
	fractol->color = 20;
	fractol->name = str;
}

void	check_arg(t_fractol *fractol)
{
	if (ft_strcmp(fractol->name, "Julia") == 0)
		julia(fractol);
	else if (ft_strcmp(fractol->name, "Mandelbrot") == 0)
		mandelbrot(fractol);
	else if (ft_strcmp(fractol->name, "Burningship") == 0)
		mandelbrot(fractol);
	else
	{
		write(1, "Usage: ./fractol <name>", 23);
		write(1, "\tJulia\tMandelbrot\tBurningship\n", 30);
	}
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Julia") == 0 || \
			ft_strcmp(av[1], "Mandelbrot") == 0 || \
			ft_strcmp(av[1], "Burningship") == 0)
		{
			fractol.ptr = mlx_init();
			fractol.win = mlx_new_window(fractol.ptr, 1000, 600, "Fractol");
			fractol.img = mlx_new_image(fractol.ptr, WIDTH + 400, HIGHT);
			fractol.str = (unsigned char *)mlx_get_data_addr(fractol.img, \
				&fractol.bpp, &fractol.size_l, &fractol.endian);
		}
		init(&fractol, av[1]);
		check_arg(&fractol);
	}
	else
	{
		write(1, "Usage: ./fractol <name>", 23);
		write(1, "\tJulia\tMandelbrot\tBurningship\n", 30);
	}
	return (0);
}
