/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:27:07 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 11:40:11 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	get_best_number(t_stack *a, int n0, int n1)
{
	int	champ0;
	int	rotate_down_n0;
	int	champ1;
	int	rotate_down_n1;

	champ0 = get_rotate_up(a, n0);
	champ1 = get_rotate_up(a, n1);
	rotate_down_n0 = get_rotate_down(a, n0);
	rotate_down_n1 = get_rotate_down(a, n1);
	if (champ0 > rotate_down_n0)
		champ0 = rotate_down_n0;
	if (champ1 > rotate_down_n1)
		champ1 = rotate_down_n1;
	if (champ0 > champ1)
		return (n1);
	else
		return (n0);
}

int	get_chunk_hold(t_stack *a, t_stack *b, int index_max)
{
	int	i;
	int	hold_first;
	int	hold_last;

	hold_first = 0;
	hold_last = 0;
	i = -1;
	while (++i < a->len)
	{
		if (get_wanted_index(a, b, a->data[i]) < index_max)
		{
			hold_first = a->data[i];
			break ;
		}
	}
	i = a->len;
	while (i--)
	{
		if (get_wanted_index(a, b, a->data[i]) < index_max)
		{
			hold_last = a->data[i];
			break ;
		}
	}
	return (get_best_number(a, hold_first, hold_last));
}

void	sort_chunk(t_stack *a, t_stack *b, int index_max)
{
	while (b->len != index_max)
	{
		rotate_to_a(a, get_chunk_hold(a, b, index_max));
		if (a->data[0] < get_min(b) || a->data[0] > get_max(b))
			rotate_to_b(b, get_max(b));
		else
			rotate_to_b(b, get_lower(b, a->data[0]));
		process_instruction("pb", a, b, false);
	}
}

void	sort_100(t_stack *a, t_stack *b)
{
	sort_chunk(a, b, 20);
	sort_chunk(a, b, 40);
	sort_chunk(a, b, 60);
	sort_chunk(a, b, 80);
	sort_chunk(a, b, 100);
	while (b->len)
	{
		rotate_to_b(b, get_max(b));
		process_instruction("pa", a, b, false);
	}
}

void	sort_500(t_stack *a, t_stack *b)
{
	sort_chunk(a, b, 45);
	sort_chunk(a, b, 90);
	sort_chunk(a, b, 135);
	sort_chunk(a, b, 180);
	sort_chunk(a, b, 225);
	sort_chunk(a, b, 270);
	sort_chunk(a, b, 315);
	sort_chunk(a, b, 360);
	sort_chunk(a, b, 405);
	sort_chunk(a, b, 450);
	sort_chunk(a, b, 500);
	while (b->len)
	{
		rotate_to_b(b, get_max(b));
		process_instruction("pa", a, b, false);
	}
}
