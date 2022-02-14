/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:43:32 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:05:56 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the length of a string.
 *
 * @param str The string to compute the length of.
 *
 * @returns The length of the string.
 */
char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (*(needle + i) == '\0')
		return ((char *)haystack);
	while (*(needle + i))
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j))
		{
			if (*(needle + j + 1) == '\0')
				return ((char *)*(haystack + i));
			j++;
		}
		i++;
	}
	return (OK);
}
