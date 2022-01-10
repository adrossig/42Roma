/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:53:12 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 11:39:41 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	insertion_sort(t_stack *stack1, t_stack *stack2)
{
	while (stack1->len)
	{
		rotate_to_a(stack1, get_min(stack1));
		process_instruction("pb", stack1, stack2, false);
	}
	while (stack2->len)
		process_instruction("pa", stack1, stack2, false);
}
