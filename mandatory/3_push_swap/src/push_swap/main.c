/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:36:38 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 11:42:10 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->len <= 5)
		sort_under_6(a, b);
	else if (a->len == 100)
		sort_100(a, b);
	else if (a->len == 500)
		sort_500(a, b);
	else
		insertion_sort(a, b);
}

int	main(int ac, char **av)
{
	int		error;
	t_stack	a;
	t_stack	b;

	if (ac > 1)
	{
		error = 0;
		a = parse_args(ac, av, &error);
		if (!error)
		{
			b = create_stack(a.len);
			if (a.len > 1 && !is_sorted(a))
				sort_stack(&a, &b);
			free(a.data);
			free(b.data);
		}
		else
			ft_putstr_fd("Error\n", 2);
	}
}
