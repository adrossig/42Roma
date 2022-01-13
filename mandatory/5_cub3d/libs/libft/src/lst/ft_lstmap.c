/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:28:36 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:38:46 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Itère sur la liste lst et applique la fonction f au
** contenu de chaque élément. Crée une nouvelle liste
** résultant des applications successives de f. la
** fonction del est la pour detruire le contenu d'un
** element si necessaire.
** Retourne la nouvelle liste ou NULL si l’allocation échoue.
** =======
** #1 : l’adresse du pointeur vers un élément.
** #2 : l’adresse de la fonction à appliquer.
** =======
** Retourne la nouvelle liste, NULL si l’allocation échoue.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;

	if (!lst)
		return (NULL);
	list = ft_lstnew(f(lst->content));
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = ft_lstnew(f(lst->content));
		if (list->next == NULL)
		{
			del(list->next);
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
