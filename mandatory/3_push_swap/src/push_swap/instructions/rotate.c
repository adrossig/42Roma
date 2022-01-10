/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:31:49 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 11:41:32 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	get_rotate_up(t_stack *stack, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len)
	{
		if (stack->data[0] == n)
			break ;
		ft_ra(stack, stack, 0);
		i++;
	}
	j = 0;
	while (j < i)
	{
		ft_rra(stack, stack, 0);
		j++;
	}
	return (i);
}

int	get_rotate_down(t_stack *stack, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len)
	{
		if (stack->data[0] == n)
			break ;
		ft_rra(stack, stack, 0);
		i++;
	}
	j = 0;
	while (j < i)
	{
		ft_ra(stack, stack, 0);
		j++;
	}
	return (i);
}

void	rotate_to_a(t_stack *a, int n)
{
	int	result_up;
	int	result_down;
	int	result;

	result_up = get_rotate_up(a, n);
	result_down = get_rotate_down(a, n);
	if (result_up == a->len || result_down == a->len)
		result = 0;
	else if (result_up <= result_down)
		result = result_up;
	else
		result = result_down;
	while (result--)
	{
		if (result_up <= result_down)
			process_instruction("ra", a, a, false);
		else
			process_instruction("rra", a, a, false);
	}
}

void	rotate_to_b(t_stack *a, int n)
{
	int	result_up;
	int	result_down;
	int	result;

	result_up = get_rotate_up(a, n);
	result_down = get_rotate_down(a, n);
	if (result_up == a->len || result_down == a->len)
		result = 0;
	else if (result_up <= result_down)
		result = result_up;
	else
		result = result_down;
	while (result--)
	{
		if (result_up <= result_down)
			process_instruction("rb", a, a, false);
		else
			process_instruction("rrb", a, a, false);
	}
}
