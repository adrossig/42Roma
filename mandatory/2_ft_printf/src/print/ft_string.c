/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:13:51 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/16 10:50:15 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_input(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
	{
		count = count + ft_width(flags.dot, ft_strlen(str), 0);
		count = count + ft_putsp(str, flags.dot, flags.fd);
	}
	else
		count = count + ft_putsp(str, ft_strlen(str), flags.fd);
	return (count);
}

/**
 * Prints a string to the console.
 *
 * @param str The string to print.
 * @param flags The formatting flags.
 *
 * @returns The number of characters printed.
 */
int	ft_string(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count = count + ft_input(str, flags);
	if (flags.dot >= 0)
		count = count + ft_width(flags.width, flags.dot, 0);
	else
		count = count + ft_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count = count + ft_input(str, flags);
	return (count);
}
