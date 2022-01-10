/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:20:44 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:48:52 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_is_prime(int nbr)
{
	int	i;

	i = 2;
	if (nbr < 0)
		return (OK);
	if (nbr == 2)
		return (2);
	while ((nbr % i != 0) && i < nbr)
	{
		i++;
		if (i == nbr)
			return (1);
	}
	return (OK);
}
