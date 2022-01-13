/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octaltodec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:28:16 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:37:30 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Converts an octal number to a decimal number.
** =======
** #1: Octal of type int.
** =======
** Returns the result of the conversion as an integer long type.
*/

long long	ft_octaltodec(int octal)
{
	int	decimal;
	int	i;

	decimal = 0;
	i = 0;
	while (octal != 0)
	{
		decimal += (octal % 10) * ft_power(8, i);
		++i;
		octal /= 10;
	}
	i = 1;
	return (decimal);
}
