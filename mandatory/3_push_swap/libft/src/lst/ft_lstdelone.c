/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:27:34 by adrossig          #+#    #+#             */
/*   Updated: 2020/10/28 18:06:10 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** Libère la mémoire de l’élément passé en argument
** en utilisant la fonction del puis avec free(3).
** La mémoire de next ne doit pas être libérée.
** =======
** #1 : l’élement à free
** #2 : l’adresse de la fonction permettant
**		de supprimer le contenu de l’élement.
** =======
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}
