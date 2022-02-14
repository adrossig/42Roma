/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:29:40 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:36:22 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Returns the size of a linked list.
 *
 * @param lst The linked list to get the size of.
 *
 * @returns The size of the linked list.
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
