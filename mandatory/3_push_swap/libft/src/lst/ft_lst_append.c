/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:53:08 by adrossig          #+#    #+#             */
/*   Updated: 2020/10/28 18:05:38 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstappend(t_list *head, t_list *last)
{
	t_list	*current;

	current = head;
	if (!current)
		return (last);
	while (current->next)
		current = current->next;
	current->next = last;
	return (head);
}
