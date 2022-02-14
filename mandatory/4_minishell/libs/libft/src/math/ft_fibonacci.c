/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:57:23 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:36:54 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the Fibonacci sequence for n terms.
 *
 * @param index The index of the Fibonacci number to compute.
 *
 * @returns The Fibonacci number at the given index.
 */
int	ft_fibonacci(int index)
{
	if (index < 0)
		return (KO);
	if (index == 0)
		return (OK);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
