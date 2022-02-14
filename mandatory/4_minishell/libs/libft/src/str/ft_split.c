/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 10:50:53 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:49:32 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_seg(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			s++;
		}
	}
	return (count);
}

static char	*f_strndup(const char *s1, size_t n)
{
	char	*cp;
	size_t	i;

	cp = (char *)malloc(sizeof(char) * n + 1);
	if (!(cp))
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(cp + i) = *(s1 + i);
		i++;
	}
	*(cp + i) = '\0';
	return (cp);
}

/**
 * Splits a string into an array of strings based on a delimiter.
 *
 * @param s The string to split.
 * @param c The delimiter.
 *
 * @returns An array of strings.
 */
char	**ft_split(const char *s, char c)
{
	char	**d;
	int		i;
	int		j;

	j = 0;
	d = (char **)malloc(sizeof(char *) * (ft_seg(s, c) + 1));
	if (!s || (!(d)))
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			i = 0;
			while (*(s + i) && *(s + i) != c)
				i++;
			*(d + j) = f_strndup(s, i);
			if (!(*(d + j++)))
				return (ft_strfree(d));
			s += i;
		}
	}
	*(d + j) = NULL;
	return (d);
}
