/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crypt_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 11:23:24 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:19:21 by arossign         ###   ########.fr       */
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

/**
 * Encrypts a string.
 *
 * @param decalage The amount to shift the characters by.
 * @param tab The string to encrypt.
 *
 * @returns None
 */
void	ft_crypt_str(int decalage, char *tab)
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
