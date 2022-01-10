/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:40:20 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:38:53 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	size_t			size;

	i = 0;
	size = ft_strlen(dest);
	while (i < n && *(src + i))
	{
		*(dest + size + i) = *(src + i);
		++i;
	}
	*(dest + size + i) = '\0';
	return (dest);
}
