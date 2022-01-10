/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:33:34 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 11:42:44 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min(t_stack *a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = a->data[0];
	while (i < a->len)
	{
		if (a->data[i] < tmp)
			tmp = a->data[i];
		i++;
	}
	return (tmp);
}

int	get_max(t_stack *a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = a->data[0];
	while (i < a->len)
	{
		if (a->data[i] > tmp)
			tmp = a->data[i];
		i++;
	}
	return (tmp);
}

int	get_upper(t_stack *a, int n)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < a->len)
	{
		if (a->data[i] > n)
		{
			tmp = a->data[i];
			break ;
		}
		i++;
	}
	while (i < a->len)
	{
		if (a->data[i] < tmp && a->data[i] > n)
			tmp = a->data[i];
		i++;
	}
	return (tmp);
}

int	get_lower(t_stack *a, int n)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < a->len)
	{
		if (a->data[i] < n)
		{
			tmp = a->data[i];
			break ;
		}
		i++;
	}
	while (i < a->len)
	{
		if (a->data[i] > tmp && a->data[i] < n)
			tmp = a->data[i];
		i++;
	}
	return (tmp);
}

int	get_wanted_index(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	counter;

	counter = 0;
	i = -1;
	while (++i < a->len)
	{
		if (a->data[i] < n)
			counter++;
	}
	i = -1;
	while (++i < b->len)
	{
		if (b->data[i] < n)
			counter++;
	}
	return (counter);
}
