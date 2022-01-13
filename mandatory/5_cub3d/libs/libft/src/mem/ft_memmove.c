/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:31:51 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 23:54:09 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Copie n octets depuis la zone mémoire src
** vers la zone mémoire dst.
** Les deux zones peuvent se chevaucher.
** =========
** #1 : la zone mémoire de destination.
** #2 : la zone mémoire source.
** #3 : le nombre d'octets à copier.
** =========
** Retourne un pointeur vers la zone mémoire dst.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
			i++;
		}
	}
	else if (dest > src && n > 0)
	{
		while (n > 0)
		{
			n--;
			*(unsigned char*)(dest + n) = *(unsigned char*)(src + n);
		}
	}
	return (dest);
}
