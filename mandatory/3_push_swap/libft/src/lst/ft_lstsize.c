/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:29:40 by adrossig          #+#    #+#             */
/*   Updated: 2021/01/14 12:51:41 by adrossig         ###   ########.fr       */
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

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (OK);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
