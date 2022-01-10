/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:43:31 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:44:37 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_arraydel_value(t_array *array, int value)
{
	if (value >= 0 && value < array->size)
	{
		if (array->array[value] != 0)
			array->array[value] = 0;
		else
			return (POSITION_EMPTY);
	}
	return (INVALID_POSITION);
}
