/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:35 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:45:45 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Copie au plus n octets de la zone mémoire src
** vers la zone mémoire dst, s'arrêtant dès qu'elle
** rencontre le caractère c.
** =========
** #1 : la chaîne de destination.
** #2 : la chaîne source.
** #3 : le caractère à chercher.
** #4 : le nombre maximal d'octets à copier.
** =========
** Retourne un pointeur sur le caractère  
** immédiatement après c dans dst, NULL si c n'a pas été trouvé
** dans les n premiers caractères de src.
*/

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		if (*(dest + i) == (unsigned char)c)
			return ((unsigned char *)(dest + (i + 1)));
		i++;
	}
	return (NULL);
}
