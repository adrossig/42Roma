/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:29:29 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:44:47 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Converts a number of any type into a hexadecimal number.
** =======
** #1: the conversion base (ex: base 10).
** #2: the number to convert.
** #3: the length.
** =======
** Returns the result of the conversion as an integer long type.
*/

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
	if (locma == NULL)
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
