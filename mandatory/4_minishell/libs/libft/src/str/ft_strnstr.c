/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:43:05 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:38:39 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(haystack + i) && i < n)
	{
		j = 0;
		while (*(needle + j) == *(haystack + i + j) && (i + j) < n)
		{
			j++;
			if (ft_strlen((char *)needle) == j)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
