/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 10:50:53 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 11:49:47 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Alloue (avec malloc(3)) un tableau
** de chaines de caractères obtenu en séparant s à
** l’aide du caractère c, utilisé comme délimiteur.
** Le tableau doit être terminé par NULL.
** =======
** #1 : La chaine de caractères à découper.
** #2 : Le caractère délimitant.
** =======
** Retourne le tableau de nouvelles chaînes de caractères,
** NULL si l’allocation échoue.
*/

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	wc;

	wc = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			wc++;
		while (*s && *s != c)
			s++;
	}
	return (wc);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	i;

	if (!s)
		return (NULL);
	dest = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			dest[i++] = ft_substr(s, 0, ft_wordlen(s, c));
		while (*s && *s != c)
			s++;
	}
	dest[i] = NULL;
	return (dest);
}
