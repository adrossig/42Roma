/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:42:59 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/27 16:28:21 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_sa(t_stack *stack_a, t_stack *stack_b, int log_level)
{
	(void)stack_b;
	if (stack_a->len >= 2)
		ft_swap(&stack_a->data[0], &stack_a->data[1]);
	display_stack(stack_a, 0, 1, log_level);
	display_stack(stack_b, -1, -1, log_level);
}

void	ft_sb(t_stack *stack_a, t_stack *stack_b, int log_level)
{
	(void)stack_a;
	if (stack_b->len >= 2)
		ft_swap(&stack_b->data[0], &stack_b->data[1]);
	display_stack(stack_a, -1, -1, log_level);
	display_stack(stack_b, 0, 1, log_level);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b, int log_level)
{
	ft_sa(stack_a, stack_b, 1);
	ft_sb(stack_a, stack_b, 1);
	display_stack(stack_a, 0, 1, log_level);
	display_stack(stack_b, 0, 1, log_level);
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b, int log_level)
{
	int	i;

	if (stack_b->len > 0)
	{
		i = stack_a->len;
		while (i--)
			stack_a->data[i + 1] = stack_a->data[i];
		stack_a->data[0] = stack_b->data[0];
		stack_a->len++;
		i = 1;
		while (i < stack_b->len)
		{
			stack_b->data[i - 1] = stack_b->data[i];
			i++;
		}
		stack_b->len--;
	}
	display_stack(stack_a, 0, -1, log_level);
	display_stack(stack_b, -1, -1, log_level);
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b, int log_level)
{
	int	i;

	if (stack_a->len > 0)
	{
		i = stack_b->len;
		while (i--)
			stack_b->data[i + 1] = stack_b->data[i];
		stack_b->data[0] = stack_a->data[0];
		stack_b->len++;
		i = 1;
		while (i < stack_a->len)
		{
			stack_a->data[i - 1] = stack_a->data[i];
			i++;
		}
		stack_a->len--;
	}
	display_stack(stack_a, -1, -1, log_level);
	display_stack(stack_b, 0, -1, log_level);
}
