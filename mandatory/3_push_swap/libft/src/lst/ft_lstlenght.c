/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlenght.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:40:09 by adrossig          #+#    #+#             */
/*   Updated: 2021/01/14 12:48:53 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** Compte le nombre d'éléments de la liste.
** =======
** #1 : le début de la liste. 
** =======
** Retourne la taille de la liste.
*/

size_t	ft_lstlenght(t_list *list)
{
	unsigned int	lenght;

	lenght = 0;
	while (list != NULL)
	{
		++lenght;
		list = list->next;
	}
	return (lenght);
}
