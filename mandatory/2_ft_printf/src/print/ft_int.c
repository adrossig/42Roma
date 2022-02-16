/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:10:53 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/16 10:52:36 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_input(char *str, int num, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0 && num < 0 && num != -2147483648)
		ft_putchar_fd('-', flags.fd);
	if (flags.dot >= 0)
		count = count + ft_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	count = count + ft_putsp(str, ft_strlen(str));
	return (count);
}

static int	ft_put_int(char *str, int num, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count = count + ft_input(str, num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count = count + ft_width(flags.width, 0, 0);
	}
	else
		count = count + ft_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count = count + ft_input(str, num, flags);
	return (count);
}

/**
 * Prints an integer to the console.
 *
 * @param i The integer to print.
 * @param flags The flags to use when printing the integer.
 *
 * @returns The number of characters printed.
 */
int	ft_int(int i, t_flags flags)
{
	int		count;
	int		num;
	char	*str;

	count = 0;
	num = i;
	if (flags.dot == 0 && i == 0)
	{
		count = count + ft_width(flags.width, 0, 0);
		return (count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1) && num != -2147483648)
	{
		if (flags.dot <= -1 && flags.zero == 1)
			ft_putsp("-", 1, flags.fd);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	str = ft_itoa(i);
	count = count + ft_put_int(str, num, flags);
	free(str);
	return (count);
}
