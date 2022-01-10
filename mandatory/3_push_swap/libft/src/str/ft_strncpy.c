/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:40:47 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:46:26 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Copie les n premiers octets de src dans dest.
** =======
** #1 : La chaine de caractères de destination.
** #2 : La chaine de caractères source.
** #3 : le nombre de caractères à copier.
** =======
** Retourne un pointeur sur dst modifiée.
*/

char	*ft_strncpy(char *dest, const char *src, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		dest[j] = src[j];
		if (!src[j])
			while (j < i)
				dest[j++] = '\0';
		j++;
	}
	return (dest);
}
