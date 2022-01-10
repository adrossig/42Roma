/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:43:19 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 11:52:34 by adrossig         ###   ########.fr       */
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

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*temp;

	temp = (char *)str;
	i = fstrlen(str);
	while (*(temp + i) != (char)c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (temp + i);
}
