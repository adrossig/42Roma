/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:01:16 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/16 10:48:17 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/**
 * Prints a formatted string to the console.
 *
 * @param format The format string.
 * @param ... The arguments to the format string.
 *
 * @returns None
 */
int	ft_width(int width, int minus, int zero)
{
	int	count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar_fd('0', flags.fd);
		else
			ft_putchar_fd(' ', flags.fd);
		width -= 1;
		count++;
	}
	return (count);
}
