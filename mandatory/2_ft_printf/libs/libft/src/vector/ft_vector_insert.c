/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 11:17:35 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:40:53 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_vector_insert(t_vector *vector, size_t i, void *item)
{
	if (!vector || !item)
		return (KO);
	if (i < 0)
		i = vector->len - 1;
	else if (i > vector->len)
		i = vector->len;
	if (vector->len + 1 > vector->max)
		ft_vector_extend(vector);
	vector->a[i] = item;
	vector->len++;
	return (OK);
}

int	ft_vector_add(t_vector *vector, void *item)
{
	if (!vector || !item)
		return (KO);
	if (vector->len + 1 > vector->max)
		ft_vector_extend(vector);
	vector->a[vector->len++] = item;
	return (OK);
}

int	ft_vector_set(t_vector *vector, size_t i, void *item)
{
	if (!vector || !item || i >= vector->len)
		return (KO);
	if (i < 0)
		i = vector->len - 1;
	vector->free(&(vector->a[i]));
	vector->a[i] = item;
	return (OK);
}
