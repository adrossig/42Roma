/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:29:29 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 13:17:32 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_tohexa(char *base, unsigned long nbr, unsigned long lenght)
{
	char			*locma;
	long			i;
	unsigned long	result;
	unsigned long	divisor;

	i = 0;
	result = 0;
	divisor = 1;
	if (!base)
		return (NULL);
	locma = malloc(sizeof(char) * 33);
	if (!(locma))
		return (NULL);
	while ((nbr / divisor) >= lenght)
		divisor *= lenght;
	while (divisor > 0)
	{
		result = (nbr / divisor) % lenght;
		*(locma + i++) = *(base + result);
		divisor /= lenght;
	}
	*(locma + i) = 0;
	return (locma);
}
