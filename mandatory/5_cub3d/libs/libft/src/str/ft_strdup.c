/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:37:32 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 23:52:30 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** - Allocates sufficient memory for a copy of the string
** - Does the copy
** - Returns a pointer to it
**   If insufficient memory is available, NULL is returned
*/

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(s1);
	dup = ft_calloc(size + 1, 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, size);
	dup[size] = 0;
	return (dup);
}
