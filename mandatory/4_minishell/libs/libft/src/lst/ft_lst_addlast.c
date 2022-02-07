/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addlast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:54:59 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/02 19:55:08 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lst_addlast(t_list **head, t_list *last)
{
	if (!last || !head)
		return ;
	if (!(*head))
		*head = last;
	else
		ft_lst_addlast(&((*head)->next), last);
}
