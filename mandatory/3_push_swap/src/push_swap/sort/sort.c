/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:35:48 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 11:40:38 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	sort_stack_3(t_stack *a, t_stack *b)
{
	if (a->len == 3 && a->data[0] < a->data[1] && a->data[0] < a->data[2]
		&& a->data[1] > a->data[2])
		process_instruction("sa", a, b, false);
	if (a->len == 3 && a->data[0] < a->data[1] && a->data[0] > a->data[2])
		process_instruction("rra", a, b, false);
	if (a->len == 3 && a->data[0] > a->data[2])
		process_instruction("ra", a, b, false);
	if (a->data[0] > a->data[1])
		process_instruction("sa", a, b, false);
}

void	sort_under_6(t_stack *a, t_stack *b)
{
	if (a->len > 3)
	{
		if (a->len == 5)
			process_instruction("pb", a, b, false);
		process_instruction("pb", a, b, false);
	}
	sort_stack_3(a, b);
	while (b->len)
	{
		if (b->data[0] < get_min(a))
			rotate_to_a(a, get_min(a));
		else if (b->data[0] > get_max(a))
			rotate_to_a(a, get_min(a));
		else
			rotate_to_a(a, get_upper(a, b->data[0]));
		process_instruction("pa", a, b, false);
	}
	rotate_to_a(a, get_min(a));
	process_instruction(NULL, a, b, true);
}
