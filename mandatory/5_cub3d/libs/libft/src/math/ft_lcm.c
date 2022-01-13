/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:30:07 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 16:37:45 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_lcm(int nbr1, int nbr2)
{
	int	min;

	if (nbr1 > nbr2)
		min = nbr1;
	else
		min = nbr2;
	while (1)
	{
		if (min % nbr1 == 0 && min % nbr2 == 0)
		{
			break ;
		}
		++min;
	}
	return (OK);
}
