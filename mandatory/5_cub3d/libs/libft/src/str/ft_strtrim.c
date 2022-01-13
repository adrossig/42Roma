/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:47:33 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:40:36 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Alloue (avec malloc(3)) et retourne une copie de
** la chaine s1, sans les caractères spécifiés
** dans set au début et à la fin de la chaine de
** caractères.
** =======
** #1 : La chaine de caractères préfixe.
** #2 : La chaine de caractères suffixe.
** =======
** Retourne un pointeur sur la nouvelle chaîne,
** ou NULL s'il l'allocation dynamique de mémoire échoue.
*/

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (*(s1 + i) && ft_strchr(set, *(s1 + i)))
		i++;
	if (!*(s1 + i))
		return (ft_strdup(""));
	while (*(s1 + j) && ft_strchr(set, *(s1 + j)))
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
