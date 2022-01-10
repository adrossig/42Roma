/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_item_label.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:53:16 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:43:34 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_add_item_label(t_dictionary *dict, char *label, void *item)
{
	unsigned int	index;

	index = ft_gethash(label);
	if (index < MAXELEMENTS)
	{
		dict->elements[index] = item;
		return (OK);
	}
	return (KO);
}
