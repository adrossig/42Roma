/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:33:47 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 11:51:02 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static void	fputchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		fputchar_fd('-', fd);
	}
	if (nbr / 10)
		ft_putnbr_fd(nbr / 10, fd);
	fputchar_fd(nbr % 10 + '0', fd);
}
