/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:54:51 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:45:45 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Alloue (avec malloc(3)) la mémoire nécessaire pour un tableau
** de count éléments de taile size octets.
** =======
** #1 : nombre d'éléments dans le tableau.
** #2 : taille en octets d'un élément.
** =======
** Retourne un pointeur sur l méoire allouée, 
** NULL si count ou size vaut 0. 
*/

void	*ft_calloc(size_t count, size_t size)
{
	char	*var;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	var = malloc(sizeof(char) * (count * size));
	if (var == NULL)
		return (NULL);
	ft_bzero((void *)var, count * size);
	return ((void *)var);
}
