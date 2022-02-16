/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:09:06 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/16 11:01:05 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_hexa_input(char *hex, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
	{
		count = count + ft_width(flags.dot - 1, ft_strlen(hex) - 1, 1, \
		flags.fd);
	}
	count = count + ft_putsp(hex, ft_strlen(hex), flags.fd);
	return (count);
}

static int	ft_put_hexa(char *hex, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count = count + ft_hexa_input(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count = count + ft_width(flags.width, 0, 0, flags.fd);
	}
	else
		count = count + ft_width(flags.width, ft_strlen(hex), flags.zero, \
		flags.fd);
	if (flags.minus == 0)
		count = count + ft_hexa_input(hex, flags);
	return (count);
}

/**
 * Prints a hexadecimal number.
 *
 * @param number The number to print.
 * @param lowercase Whether to print the number in lowercase.
 * @param flags The flags to use.
 *
 * @returns The number of characters printed.
 */
int	ft_hexa(unsigned int number, int lowercase, t_flags flags)
{
	char	*hex;
	int		count;

	number = (unsigned int)(4294967295 + 1 + number);
	count = 0;
	if (flags.dot == 0 && number == 0)
	{
		count = count + ft_width(flags.width, 0, 0, flags.fd);
		return (count);
	}
	hex = ft_utl_base((unsigned long long)number, 16);
	if (lowercase == 1)
		hex = ft_tolower_str(hex);
	count = count + ft_put_hexa(hex, flags);
	free(hex);
	return (count);
}
