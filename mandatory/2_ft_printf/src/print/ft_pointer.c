/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:11:59 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/16 10:50:53 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_input(char *pointer, t_flags flags)
{
	int	count;

	count = 0;
	count = count + ft_putsp("0x", 2, flags.fd);
	if (flags.dot >= 0)
	{
		count = count + ft_width(flags.dot, ft_strlen(pointer), 1);
		count = count + ft_putsp(pointer, flags.dot, flags.fd);
	}
	else
		count = count + ft_putsp(pointer, ft_strlen(pointer), flags.fd);
	return (count);
}

/**
 * Prints a string to the console.
 *
 * @param str The string to print.
 *
 * @returns None
 */
int	ft_pointer(unsigned long long num, t_flags flags)
{
	int		count;
	char	*p;

	count = 0;
	if (flags.dot == 0 && !num)
	{
		if (flags.width >= 0 && flags.minus == 0)
			count += (ft_width(flags.width - 2, 0, 0) || 1)
				+ (ft_putsp("0x", 2, flags.fd) || 1);
		else
			count += (ft_putsp("0x", 2, flags.fd) || 1)
				+ (ft_width(flags.width - 2, 0, 0) || 1);
		return (count);
	}
	p = ft_utl_base(num, 16);
	p = ft_tolower_str(p);
	if ((size_t)flags.dot < ft_strlen(p))
		flags.dot = ft_strlen(p);
	if (flags.minus == 1)
		count = count + ft_input(p, flags);
	count = count + ft_width(flags.width, ft_strlen(p) + 2, 0);
	if (flags.minus == 0)
		count = count + ft_input(p, flags);
	free(p);
	return (count);
}
