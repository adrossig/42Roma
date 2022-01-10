/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:32:05 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:45:45 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Remplit les n premiers octets de la zone mémoire
** pointée par s avec l'octet c.
** =========
** #1 : la zone mémoire pointée.
** #2 : l'octet donné pour le remplissage.
** #3 : le nombre d'octets à remplir. 
** =========
** Retourne un pointeur vers la zone mémoire s.
*/

void	*ft_memset(void *str, int i, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		*(((unsigned char *)str) + j) = (unsigned char)i;
		j++;
	}
	return (str);
}
