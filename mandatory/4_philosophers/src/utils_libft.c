/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:28:52 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/04 11:28:53 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0)
	{
		while (s && *s)
		{
			write(fd, &*s, 1);
			s++;
		}
	}
}

void	ft_putnbr_fd(long int ln, int fd)
{
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar_fd('-', fd);
	}
	if (ln >= 10)
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
	else
	{
		if (fd >= 0)
			ft_putchar_fd(ln + 48, fd);
	}
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
