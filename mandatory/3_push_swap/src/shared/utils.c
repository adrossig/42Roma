/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:39:32 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 11:43:16 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	display_stack(t_stack *stack, int index_a, int index_b,
	int log_level)
{
	int		i;

	if (log_level >= 2)
	{
		ft_putstr("|");
		i = 0;
		while (i < stack->len)
		{
			if ((i == index_a || i == index_b) && log_level >= 3)
				ft_putstr("\033[1;31m");
			ft_putnbr_fd(stack->data[i++], STDOUT_FILENO);
			ft_putstr("\033[0m");
			ft_putstr("|");
		}
		ft_putstr(" len: ");
		ft_putnbr_fd(stack->len, STDOUT_FILENO);
		ft_putstr("\n");
	}
}

t_bool	is_sorted(t_stack stack)
{
	int	i;

	i = 1;
	while (i < stack.len)
	{
		if (stack.data[i - 1] > stack.data[i])
			return (false);
		i++;
	}
	return (true);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_stack	create_stack(int len)
{
	t_stack	stack;

	stack.len = 0;
	stack.data = ft_calloc(len, sizeof(int));
	return (stack);
}
