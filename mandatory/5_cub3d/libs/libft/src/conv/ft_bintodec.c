/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:53:06 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:37:30 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Converts a binary into a decimal number.
** =======
** #1: Binary of type int
** =======
** Returns the result of the conversion as an integer of type int.
*/

int	ft_bintodec(int binary)
{
	int	i;
	int	mult;

	i = 0;
	mult = 1;
	while (binary != 0)
	{
		i += (binary % 10) * mult;
		binary /= 10;
		mult *= 2;
	}
	return (i);
}
