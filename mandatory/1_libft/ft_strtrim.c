/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:47:33 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 11:53:00 by adrossig         ###   ########.fr       */
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

static char	*fstrchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == 0)
		return ((char *)str);
	return (NULL);
}

static char	*fstrdup(const char *str)
{
	char			*dest;
	unsigned int	i;

	dest = (char *)malloc(sizeof(char) * fstrlen((char *)str) + 1);
	if (!(dest))
		return (NULL);
	i = 0;
	while (i < fstrlen((char *)str))
	{
		*(dest + i) = *(str + i);
		++i;
	}
	*(dest + i) = '\0';
	return (dest);
}

static char	*fsubstr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (!(str))
		return (NULL);
	j = 0;
	if (start <= fstrlen(s))
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	if (!set)
		return (fstrdup(s1));
	i = 0;
	j = fstrlen(s1) - 1;
	while (s1[i] && fstrchr(set, s1[i]))
		i++;
	if (!s1[i])
		return (fstrdup(""));
	while (s1[j] && fstrchr(set, s1[j]))
		j--;
	return (fsubstr(s1, i, j - i + 1));
}
