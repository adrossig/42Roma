/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:15:09 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/16 10:49:48 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_input(char *u_num, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
		count = count + ft_width(flags.dot - 1, ft_strlen(u_num) - 1, 1);
	count = count + ft_putsp(u_num, ft_strlen(u_num), flags.fd);
	return (count);
}

/**
 * Take a string to pass them in an unsigned int
 *
 * @param str The string to print.
 * @param flags The flags to use for printing.
 *
 * @returns The unsigned int with the precision specified.
 */
static int	ft_put_uint(char *u_num, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count = count + ft_input(u_num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(u_num))
		flags.dot = ft_strlen(u_num);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count = count + ft_width(flags.width, 0, 0);
	}
	else
		count = count + ft_width(flags.width, ft_strlen(u_num), flags.zero);
	if (flags.minus == 0)
		count = count + ft_input(u_num, flags);
	return (count);
}

/**
 * Prints an unsigned integer to the console.
 *
 * @param number The unsigned integer to print.
 * @param flags The flags to use for printing.
 *
 * @returns The number of characters printed.
 */
int	ft_uint(unsigned int number, t_flags flags)
{
	int		count;
	char	*u_num;

	count = 0;
	number = (unsigned int)(4294967295 + 1 + number);
	if (flags.dot == 0 && number == 0)
	{
		count = count + ft_width(flags.width, 0, 0);
		return (count);
	}
	u_num = ft_uitoa(number);
	count = ft_put_uint(u_num, flags);
	free(u_num);
	return (count);
}
