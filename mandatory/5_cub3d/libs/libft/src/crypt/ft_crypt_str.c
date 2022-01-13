/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crypt_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 11:23:24 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 23:48:01 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	entry(int min, int max, int nbr)
{
	static int	maximum;
	int			result;

	max++;
	maximum = (max - min);
	result = (nbr - min);
	result = nbr % maximum;
	if (result < 0)
		result += maximum;
	result += min;
	return (result);
}

void		ft_crypt_str(int decalage, char *tab)
{
	int	minimum;
	int	maximum;
	int	i;
	int	size;

	minimum = 32;
	maximum = 126;
	size = ft_strlen(tab);
	i = 0;
	while (i < size)
	{
		*(tab + i) = entry(minimum, maximum, *(tab + 1) + decalage);
		i++;
	}
}
