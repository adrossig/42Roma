/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:05:27 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:37:30 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Converts a decimal to a hexadecimal number.
** =======
** #1: Decimal type int
** =======
** Returns the result of the conversion as an integer of type char.
*/

char	*ft_dectohexa(int decimal)
{
	int		remainder;
	int		i;
	char	hexadecimal[3];

	remainder = 0;
	i = 0;
	while (decimal > 0 && i >= 0)
	{
		remainder = decimal % 16;
		if (remainder < 10)
			*(hexadecimal + i) = (char)remainder + 48;
		else
			*(hexadecimal + i) = (char)remainder + 55;
		decimal /= 16;
		i++;
	}
	*(hexadecimal + i) = '\0';
	return (ft_strrev(hexadecimal));
}
