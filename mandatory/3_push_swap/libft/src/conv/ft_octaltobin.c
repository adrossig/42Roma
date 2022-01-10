/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octaltobin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:02:41 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:44:47 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Converts an octal number to a binary number.
** =======
** #1: Octal type int.
** =======
** Returns the result of the conversion as an integer long type.
*/

long long	ft_octaltobin(int octal)
{
	int			decimal;
	int			i;
	long long	binary;

	decimal = 0;
	i = 0;
	binary = 0;
	while (octal != 0)
	{
		decimal += (octal % 10) * ft_power(8, i);
		++i;
		octal /= 10;
	}
	i = 1;
	while (decimal != 0)
	{
		binary += (decimal % 2) * i;
		decimal /= 2;
		i *= 10;
	}
	return (binary);
}
