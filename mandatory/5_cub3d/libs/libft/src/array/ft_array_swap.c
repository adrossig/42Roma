/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:49:21 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:37:58 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_array_swap(t_array *array, int position1, int position2)
{
	int	temp;

	temp = array->array[position1];
	array->array[position1] = array->array[position2];
	array->array[position2] = temp;
}
