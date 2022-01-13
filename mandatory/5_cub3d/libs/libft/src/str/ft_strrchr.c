/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:43:19 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 23:52:24 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Recherche le caractère c dans la chaîne s.
** =========
** #1 : la chaîne de caractère à parser.
** #2 : le caractère à chercher.
** =========
** Retourne un pointeur sur la dernière occurence
** du caractère correspondant, NULL si il n'a pas été trouvé.
*/

char	*ft_strrchr(const char *str, int c)
{
	const char	*found;
	const char	*p;

	c = (unsigned char)c;
	if (c == '\0')
		return (ft_strchr(str, '\0'));
	found = NULL;
	p = ft_strchr(str, c);
	while (p != NULL)
	{
		found = p;
		str = p + 1;
	}
	return ((char *)found);
}
