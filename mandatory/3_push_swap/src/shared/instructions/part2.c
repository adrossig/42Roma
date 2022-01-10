/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:44:36 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/27 15:25:57 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_ra(t_stack *stack_a, t_stack *stack_b, int log_level)
{
	int		tmp;
	int		i;

	(void)stack_b;
	if (stack_a->len >= 2)
	{
		tmp = stack_a->data[0];
		i = 1;
		while (i < stack_a->len)
		{
			stack_a->data[i - 1] = stack_a->data[i];
			i++;
		}
		stack_a->data[i - 1] = tmp;
	}
	display_stack(stack_a, 0, stack_a->len - 1, log_level);
	display_stack(stack_b, -1, -1, log_level);
}

void	ft_rb(t_stack *stack_a, t_stack *stack_b, int log_level)
{
	int		tmp;
	int		i;

	(void)stack_a;
	if (stack_b->len >= 2)
	{
		tmp = stack_b->data[0];
		i = 1;
		while (i < stack_b->len)
		{
			stack_b->data[i - 1] = stack_b->data[i];
			i++;
		}
		stack_b->data[i - 1] = tmp;
	}
	display_stack(stack_a, -1, -1, log_level);
	display_stack(stack_b, 0, stack_b->len - 1, log_level);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b, int log_level)
{
	ft_ra(stack_a, stack_b, 0);
	ft_rb(stack_a, stack_b, 0);
	display_stack(stack_a, 0, stack_a->len - 1, log_level);
	display_stack(stack_b, 0, stack_b->len - 1, log_level);
}
