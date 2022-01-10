/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:39:49 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:34:14 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*s2;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(s2))
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(s2 + i) = f(*(s + i));
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
