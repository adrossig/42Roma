/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:12:50 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:44:47 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Converts a decimal to a binary number.
** =======
** #1: Decimal type int.
** =======
** Returns the result of the conversion as an integer long type.
*/

long long	ft_dectobin(int decimal)
{
	long long	binary;
	int			i;

	i = 1;
	binary = 0;
	while (decimal != 0)
	{
		decimal /= 2;
		binary += decimal % 2 * i;
		i *= 10;
	}
	return (binary);
}

long long	ft_dectobin_recursive(int decimal)
{
	if (decimal == 0)
		return (OK);
	else
		return (decimal % 2 + 10 * ft_dectobin_recursive(decimal / 2));
}
