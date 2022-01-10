/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:41:18 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 12:17:44 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int	*data;
	int	len;
}	t_stack;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

t_bool			is_integer(char *str);
t_bool			do_instruction(char *inst, t_stack *stack_a, t_stack *stack_b,
					int log_level);
void			display_stack(t_stack *stack, int index_a, int index_b,
					int log_level);
t_stack			parse_args(int ac, char **av, int *error);
void			ft_sa(t_stack *stack_a, t_stack *stack_b, int log_level);
void			ft_sb(t_stack *stack_a, t_stack *stack_b, int log_level);
void			ft_ss(t_stack *stack_a, t_stack *stack_b, int log_level);
void			ft_pa(t_stack *stack_a, t_stack *stack_b, int log_level);
void			ft_pb(t_stack *stack_a, t_stack *stack_b, int log_level);
void			ft_ra(t_stack *stack_a, t_stack *stack_b, int log_level);
void			ft_rb(t_stack *stack_a, t_stack *stack_b, int log_level);
void			ft_rra(t_stack *stack_a, t_stack *stack_b, int log_level);
void			ft_rrb(t_stack *stack_a, t_stack *stack_b, int log_level);
void			ft_rrr(t_stack *stack_a, t_stack *stack_b, int log_level);
void			ft_rr(t_stack *stack_a, t_stack *stack_b, int log_level);
void			ft_swap(int *a, int *b);
t_stack			create_stack(int len);
t_bool			is_sorted(t_stack stack);

#endif
