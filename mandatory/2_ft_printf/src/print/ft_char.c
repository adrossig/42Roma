/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:57:30 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/16 10:45:56 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/**
 * Prints a character to the console.
 *
 * @param c The character to print.
 * @param flags The flags to use for printing.
 *
 * @returns The number of characters printed.
 */
int	ft_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar_fd(c, flags.fd);
	count = ft_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar_fd(c, flags.fd);
	return (count + 1);
}
