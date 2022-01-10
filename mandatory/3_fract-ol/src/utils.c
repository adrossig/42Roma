#include "../includes/fractol.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	set_color(t_fractol *fractol, int color)
{
	fractol->index = (4 * 1000 * fractol->y_y) + fractol->x_x * 4;
	fractol->str[fractol->index] = (fractol->itier * fractol->color \
		+ 680 + 179) * color;
	fractol->str[fractol->index + 1] = (fractol->itier * fractol->color \
		+ 42 + 84) * color;
	fractol->str[fractol->index + 2] = (fractol->itier * fractol->color \
		+ 936 + 45) * color;
	fractol->str[fractol->index + 3] = 0;
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	map(t_fractol *fractol)
{
	fractol->x = fractol->x_x / (WIDTH / (fractol->end_x - fractol->start_x)) \
		+ fractol->start_x;
	fractol->y = fractol->y_y / (HIGHT / (fractol->end_y - fractol->start_y)) \
		+ fractol->start_y;
	fractol->x_o = fractol->x;
	fractol->y_o = fractol->y;
}

void	itier_loop(t_fractol *fractol)
{
	while (fractol->itier < fractol->max)
	{
		fractol->xtemp = fractol->x * fractol->x - fractol->y * fractol->y;
		if (ft_strcmp(fractol->name, "Burningship") == 0)
			fractol->ytemp = ft_abs(2 * fractol->x * fractol->y);
		else
			fractol->ytemp = 2 * fractol->x * fractol->y;
		fractol->x = fractol->xtemp + fractol->x_o;
		fractol->y = fractol->ytemp + fractol->y_o;
		if (fractol->x * fractol->x + fractol->y * fractol->y > 4)
			break ;
		fractol->itier++;
	}
}
