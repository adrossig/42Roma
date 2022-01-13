/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:34:16 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 16:37:33 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_gcd(int nbr1, int nbr2)
{
	if (nbr1 < 0)
		nbr1 = -nbr1;
	if (nbr2 < 0)
		nbr2 = -nbr2;
	if (nbr2)
	{
		while ((nbr1 %= nbr2) && (nbr2 %= nbr1))
			return (nbr1 + nbr2);
	}
	return (OK);
}
