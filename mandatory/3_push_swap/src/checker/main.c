/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:01:43 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 13:09:49 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static int	wait_instruction(t_stack *stack_a, t_stack *stack_b, int log)
{
	char	*inst;

	while (get_next_line(STDIN_FILENO, &inst))
	{
		if (!do_instruction(inst, stack_a, stack_b, log))
			ft_putstr_fd("Error\n", 2);
		free(inst);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		error;
	t_stack	stack_a;
	t_stack	stack_b;
	int		log_level;

	log_level = 0;
	error = 0;
	stack_a = parse_args(ac, av, &error);
	if (!error)
	{
		stack_b = create_stack(stack_a.len);
		wait_instruction(&stack_a, &stack_b, log_level);
		if (is_sorted(stack_a) && stack_b.len == 0)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		free(stack_a.data);
		free(stack_b.data);
	}
	else if (ac > 1)
		ft_putstr_fd("Error\n", 2);
}
