/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:30:33 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 10:22:19 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Alloue et initialise une chaîne avec un caractère donné.
** =========
** #1 : la taille de la chaîne à créer.
** #2 : le caractère servant à initialiser la chaîne.
** =========
** Retourne la chaîne résultante, NULL si l'allocation échoue.
*/

char	*ft_calloc_flag(size_t count, int c)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = (char *)malloc(sizeof(char) * (count + 1));
	if (mem != NULL)
	{
		while (i < count)
		{
			mem[i] = c;
			i++;
		}
		mem[i] = '\0';
	}
	return (mem);
}
