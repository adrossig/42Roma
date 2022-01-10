/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:53:06 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:50:50 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
