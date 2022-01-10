/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:39:02 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 11:51:32 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	fstrlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i))
		++i;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(dest + i) != '\0' && i < size)
		i++;
	while (*(src + j) && i + j + 1 < size)
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	if (i != size)
		*(dest + i + j) = '\0';
	return (i + fstrlen(src));
}
