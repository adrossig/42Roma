/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 10:50:53 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 23:51:46 by adrossig         ###   ########.fr       */
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

static int	ft_seg(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			s++;
		}
	}
	return (count);
}

static char	*f_strndup(const char *s1, size_t n)
{
	char	*cp;
	size_t	i;

	cp = (char *)malloc(sizeof(char) * n + 1);
	if (cp == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(cp + i) = *(s1 + i);
		i++;
	}
	*(cp + i) = '\0';
	return (cp);
}

char		**ft_split(const char *s, char c)
{
	char	**d;
	int		i;
	int		j;

	j = 0;
	d = (char **)malloc(sizeof(char *) * (ft_seg(s, c) + 1));
	if (!s || d == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			i = 0;
			while (*(s + i) && *(s + i) != c)
				i++;
			if (!(*(d + j++) = f_strndup(s, i)))
				return (ft_strfree(d));
			s += i;
		}
	}
	*(d + j) = NULL;
	return (d);
}
