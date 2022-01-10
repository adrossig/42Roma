/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:45:42 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/27 15:26:00 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_rra(t_stack *stack_a, t_stack *stack_b, int log_level)
{
	int		tmp;
	int		i;

	(void)stack_b;
	if (stack_a->len >= 2)
	{
		tmp = stack_a->data[stack_a->len - 1];
		i = stack_a->len - 1;
		while (i--)
			stack_a->data[i + 1] = stack_a->data[i];
		stack_a->data[0] = tmp;
	}
	display_stack(stack_a, 0, stack_a->len - 1, log_level);
	display_stack(stack_b, -1, -1, log_level);
}

void	ft_rrb(t_stack *stack_a, t_stack *stack_b, int log_level)
{
	int		tmp;
	int		i;

	(void)stack_a;
	if (stack_b->len >= 2)
	{
		tmp = stack_b->data[stack_b->len - 1];
		i = stack_b->len - 1;
		while (i--)
			stack_b->data[i + 1] = stack_b->data[i];
		stack_b->data[0] = tmp;
	}
	display_stack(stack_a, -1, -1, log_level);
	display_stack(stack_b, 0, stack_b->len - 1, log_level);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b, int log_level)
{
	ft_rra(stack_a, stack_b, 0);
	ft_rrb(stack_a, stack_b, 0);
	display_stack(stack_a, 0, stack_a->len - 1, log_level);
	display_stack(stack_b, 0, stack_b->len - 1, log_level);
}
