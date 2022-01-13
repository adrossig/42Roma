/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:39:19 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 23:51:25 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Copie la chaîne de caractères src dans dst
** jusqu'à dstsize caractères.
** =========
** #1 : une chaîne de caractères de destination.
** #2 : une chaîne de caractères source.
** #3 : le nombre maximal de caractères de dst à ajouter.
** =========
** Retourne le nombre total de caractères de la chaîne dst
** après copie.
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	tmp;

	tmp = 0;
	if (!src)
		return (OK);
	if (size > 0)
	{
		while (*(src + tmp) && tmp + 1 < size)
		{
			*(dest + tmp) = *(src + tmp);
			tmp++;
		}
		*(dest + tmp) = '\0';
	}
	return (ft_strlen(src));
}
