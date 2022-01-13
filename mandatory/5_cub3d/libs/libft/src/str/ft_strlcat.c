/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:39:02 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:40:36 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Concatène la chaîne de caractères src à la fin de dst,
** en veillant à ce que le nombre de cartères de dst après
** concaténation ne dépasse pas dstsize.
** =========
** #1 : une chaîne de caractères de destination.
** #2 : une chaîne de caractères source.
** #3 : le nombre maximal de caractères de dst à ajouter.
** =========
** Retourne le nombre total de caractères de la chaîne dst
** avant concaténation auquel on ajoute celui de src.
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const char	*odst;
	const char	*osrc;
	size_t		n;
	size_t		dlen;

	odst = dest;
	osrc = src;
	n = size;
	while (n-- != 0 && *dest != '\0')
		dest++;
	dlen = dest - odst;
	n = size - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dest++ = *src;
			n--;
		}
		src++;
	}
	*dest = '\0';
	return (dlen + (src - osrc));
}
