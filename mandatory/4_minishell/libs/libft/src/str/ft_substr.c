/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:43:49 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/12 00:07:03 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the substring of a string.
 *
 * @param s The string to be sliced.
 * @param start The start index of the slice.
 * @param len The length of the slice.
 *
 * @returns The substring of the string.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	j = 0;
	if (start <= ft_strlen(s))
	{
		i = start;
		while (i < len + start)
		{
			*(str + j++) = *(s + i);
			i++;
		}
	}
	*(str + j) = '\0';
	return (str);
}
