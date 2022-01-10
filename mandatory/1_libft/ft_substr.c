/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:43:49 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 11:53:16 by adrossig         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
