/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:32:37 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:38:31 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the power of a number.
 *
 * @param nbr The number to be raised to the power.
 * @param power The power to raise the number to.
 *
 * @returns The result of the power operation.
 */
int	ft_power(int nbr, int power)
{
	if (nbr < 0)
		return (OK);
	if (nbr == 0)
		return (1);
	return (nbr * ft_power(nbr, power - 1));
}
