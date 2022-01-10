/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:40:06 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 11:52:03 by adrossig         ###   ########.fr       */
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

static char	*ft_strnew(size_t size)
{
	char	*locma;

	locma = (char *)malloc(sizeof(char) * (size + 1));
	if (!(locma))
		return (NULL);
	ft_bzero(locma, size);
	return (locma);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	size;

	if (!s || !f)
		return (NULL);
	size = fstrlen(s);
	str = ft_strnew(size);
	while (size--)
		str[size] = f(size, s[size]);
	return (str);
}
