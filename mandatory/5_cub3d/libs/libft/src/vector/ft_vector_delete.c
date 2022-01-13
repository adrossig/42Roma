/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 11:15:52 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 16:35:51 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_vector_delete(t_vector *vector, size_t i)
{
	if (!vector || !vector->a || i >= vector->len)
		return (KO);
	if (i <= 0)
		i = vector->len - 1;
	vector->free(&(vector->a[i--]));
	while (++i < vector->len - 1)
		vector->a[i] = vector->a[i + 1];
	vector->a[i] = NULL;
	vector->len--;
	return (OK);
}

int	ft_vector_free(t_vector *vector)
{
	size_t	i;

	if (!vector || !vector->a)
		return (KO);
	i = 0;
	while (i < vector->len)
		vector->free(&(vector->a[i++]));
	ft_memdel((void**)&(vector->a));
	vector->free = NULL;
	vector->dup = NULL;
	vector->len = 0;
	vector->max = 0;
	return (OK);
}
