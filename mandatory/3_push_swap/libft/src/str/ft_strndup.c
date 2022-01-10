/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:41:03 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:46:26 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Alloue avec malloc (3) un emplacement mémoire
** dans lequelle elle copie les n premiers caractères de s1.
** =========
** #1 : une chaîne de caractères à dupliquer.
** #2 : la taille de la partie à dupliquer.
** =========
** Retourne un pointeur sur la chaîne dupliquée depuis s1,
** ou NULL s'il l'allocation dynamique de mémoire échoue.
*/

char	*ft_strndup(const char *s, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (n + 1));
	if (s2 == NULL)
		return (NULL);
	while (*(s + i) && i < n)
	{
		*(s2 + i) = *(s + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
