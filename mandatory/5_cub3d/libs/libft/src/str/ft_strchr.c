/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:36:12 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 17:05:02 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** - Locates 'first' occurrence of 'c'(converted to a char) pointed to by 's'.
** - The terminating NULL is considered to be part of string.
**   (therefore if 'c' is '', the functions locate terminating '')
** - Returns a pointer to the located character,
**   or NULL if the character does not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	if (s == 0)
		return (0);
	i = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
