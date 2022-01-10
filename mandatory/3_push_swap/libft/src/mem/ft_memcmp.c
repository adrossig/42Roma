/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:31:09 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:45:45 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Compare les n premiers octets des zones mémoire s1 et s2.
** =========
** #1 : la zone mémoire pointée par s1.
** #2 : la zone mémoire pointée par s1.
** #3 : le nombre d'octets à examiner.
** =========
** Retourne un entier inférieur, égal, ou supérieur à zéro,
** si s1 est respectivement inférieure, égale ou supérieur à s2.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (n != 0)
	{
		p1 = s1;
		p2 = s2;
		while (--n != 0)
		{
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
		}
	}
	return (OK);
}
