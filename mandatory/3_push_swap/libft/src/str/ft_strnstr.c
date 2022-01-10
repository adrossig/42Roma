/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:43:05 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:46:26 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Cherche la première occurrence de la sous-chaîne needle
** au sein de la chaîne haystack dans laquelle pas plus de
** len caractères sont examinés.
** Les caractères nuls de fin ne sont pas comparés.
** =========
** #1 : une chaîne de caractères à examiner.
** #2 : une chaîne de caractères à chercher.
** #3 : le nombre maximal de caractères à parser. 
** =========
** Retourne un pointeur sur le premier caractère de la première
** occurence de needle dans haystack, haystack si needle est une chaîne vide,
** ou NULL si needle n'est pas trouvée dans haystack.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(haystack + i) && i < n)
	{
		j = 0;
		while (*(needle + j) == *(haystack + i + j) && (i + j) < n)
		{
			j++;
			if (ft_strlen((char *)needle) == j)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
