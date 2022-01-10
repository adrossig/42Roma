/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:39:19 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 11:51:45 by adrossig         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	tmp;

	tmp = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (*(src + tmp) && tmp + 1 < size)
		{
			*(dest + tmp) = *(src + tmp);
			tmp++;
		}
		*(dest + tmp) = '\0';
	}
	return (fstrlen(src));
}
