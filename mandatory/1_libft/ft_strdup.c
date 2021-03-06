/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:27 by arossign          #+#    #+#             */
/*   Updated: 2022/01/10 14:48:33 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	fstrlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i))
		++i;
	return (i);
}

char	*ft_strdup(const char *str)
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
