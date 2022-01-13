/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_erase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:46:55 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:37:58 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_array_erase(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->size)
	{
		array->array[i] = 0;
		i++;
	}
	return (OK);
}
