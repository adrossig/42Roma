/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintooctal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:53:10 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:44:47 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Converts a binary into an octal number.
** =======
** #1: Binary of type int
** =======
** Returns the result of the conversion as an integer of type int.
*/

int	ft_bintooctal(int binary)
{
	int	octal;
	int	decimal;
	int	i;

	octal = 0;
	decimal = 0;
	i = 0;
	while (binary != 0)
	{
		decimal = decimal + (binary % 10) * ft_power(2, i);
		i++;
		binary = binary / 10;
	}
	i = 1;
	while (decimal != 0)
	{
		octal += (decimal % 8) * i;
		decimal /= 8;
		i *= 10;
	}
	return (octal);
}
