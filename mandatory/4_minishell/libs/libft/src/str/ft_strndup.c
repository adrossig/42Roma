/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:41:03 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:33:16 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (n + 1));
	if (!(s2))
		return (NULL);
	while (*(s + i) && i < n)
	{
		*(s2 + i) = *(s + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
