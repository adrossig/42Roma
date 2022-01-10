/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:01:16 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 18:00:42 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_width(int width, int minus, int zero)
{
	int	count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count++;
	}
	return (count);
}
