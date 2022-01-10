/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:38:59 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 11:46:08 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_args(int ac, char **av)
{
	int		i;
	int		j;
	char	**nums;
	int		len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		nums = ft_split(av[i], ' ');
		j = 0;
		while (nums[j])
		{
			if (is_integer(nums[j]))
				len++;
			else
				return (-1);
			free(nums[j]);
			j++;
		}
		free(nums);
		i++;
	}
	return (len);
}

static int	*create_data(int ac, char **av, int len)
{
	int		i;
	int		j;
	char	**nums;
	int		*dst;
	int		index;

	dst = malloc(len * sizeof(int));
	if (!dst)
		return (NULL);
	i = 1;
	index = 0;
	while (i < ac)
	{
		j = 0;
		nums = ft_split(av[i], ' ');
		while (nums[j])
		{
			dst[index++] = ft_atoi(nums[j]);
			free(nums[j++]);
		}
		free(nums);
		i++;
	}
	return (dst);
}

static t_bool	find_duplicates(t_stack stack)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < stack.len)
	{
		temp = stack.data[i];
		j = i + 1;
		while (j < stack.len)
		{
			if (stack.data[i] == stack.data[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

t_stack	parse_args(int ac, char **av, int *error)
{
	t_stack		stack;

	stack.len = 0;
	if (ac >= 2)
	{
		stack.len = check_args(ac, av);
		if (stack.len == -1)
			*error = 2;
		else
		{
			stack.data = create_data(ac, av, stack.len);
			if (find_duplicates(stack))
			{
				*error = 3;
				free(stack.data);
			}
		}
	}
	else
		*error = 1;
	return (stack);
}
