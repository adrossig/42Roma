/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_armstrong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:09:33 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:46:51 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_armstrong(int num)
{
	int		original_num;
	int		remainder;
	int		i;
	float	result;

	i = 0;
	result = 0.0;
	original_num = num;
	while (original_num != 0)
	{
		original_num /= 10;
		++i;
	}
	original_num = num;
	while (original_num != 0)
	{
		remainder = original_num % 10;
		result += ft_power(remainder, i);
		original_num /= 10;
	}
	if ((int)result == num)
		ft_putstr("Is an Armstrong number.");
	else
		ft_putstr("Is not an Armstrong number.");
}
