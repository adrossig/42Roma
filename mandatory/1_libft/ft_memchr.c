/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:50 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/27 16:37:10 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			j;
	unsigned char	*dest;

	j = 0;
	dest = (unsigned char *)str;
	while (n-- > 0)
	{
		if (dest[j] == (unsigned char)c)
			return (dest + j);
		j++;
	}
	return (NULL);
}
