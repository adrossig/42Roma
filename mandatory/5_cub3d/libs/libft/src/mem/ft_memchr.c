/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:50 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:39:24 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Examine les n premiers octets de la zone mémoire
** pointée par s à la recherche du caractère c.
** Le premier octet correspondant à c (interprété comme
** unsigned char) arrête l'opération.
** =========
** #1 : la zone mémoire pointée.
** #2 : le caractère à rechercher.
** #3 : le nombre d'octets à examiner.
** =========
** Retourne un pointeur vers l'octet correspondant
** ou NULL s'il n'est pas présent dans la zone concernée.
*/

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*p;

	if (n != 0)
	{
		p = str;
		while (--n != 0)
		{
			if (*p++ == (unsigned char)c)
				return ((void *)(p - 1));
		}
	}
	return (NULL);
}
