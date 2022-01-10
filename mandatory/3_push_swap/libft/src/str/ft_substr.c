/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:43:49 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:46:26 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractères
** issue de la chaine ’s’. Cette nouvelle chaine commence à l’index 
** start et a pour taille maximale len.
** =======
** #1 : la chîne de laquelle extraire la nouvelle chaîne.
** #2 : l'index de début de la nouvelle chaîne s.
** #3 : la taille maximale de la nouvelle chapine.
** =======
** Retourne un pointeur sur la nouvelle chaîne,
** ou NULL s'il l'allocation dynamique de mémoire échoue.
*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	if (start <= ft_strlen(s))
	{
		i = start;
		while (i < len + start)
		{
			*(str + j++) = *(s + i);
			i++;
		}
	}
	*(str + j) = '\0';
	return (str);
}
