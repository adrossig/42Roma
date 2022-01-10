/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlenght.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:40:09 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:40:42 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
