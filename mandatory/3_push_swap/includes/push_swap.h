/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:53:44 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 12:17:32 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

void	process_instruction(char *inst, t_stack *a, t_stack *b, t_bool clear);
void	insertion_rot(t_stack *stack, t_stack *stack_b, int n);
void	sort_100(t_stack *a, t_stack *b);
void	sort_500(t_stack *a, t_stack *b);
void	rotate_to_a(t_stack *a, int n);
void	rotate_to_b(t_stack *a, int n);
void	sort_under_6(t_stack *a, t_stack *b);
void	insertion_sort(t_stack *stack1, t_stack *stack2);
int		get_min(t_stack *a);
int		get_max(t_stack *a);
int		get_upper(t_stack *a, int n);
int		get_rotate_up(t_stack *stack, int n);
int		get_rotate_down(t_stack *stack, int n);
int		get_wanted_index(t_stack *a, t_stack *b, int n);
int		get_lower(t_stack *a, int n);

#endif
