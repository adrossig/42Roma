/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:11:59 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/09 19:08:05 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_input(char *pointer, t_flags flags)
{
	int	count;

	count = 0;
	count = count + ft_putsp("0x", 2);
	if (flags.dot >= 0)
	{
		count = count + ft_width(flags.dot, ft_strlen(pointer), 1);
		count = count + ft_putsp(pointer, flags.dot);
	}
	else
		count = count + ft_putsp(pointer, ft_strlen(pointer));
	return (count);
}

int	ft_pointer(unsigned long long num, t_flags flags)
{
	int		count;
	char	*p;

	count = 0;
	if (flags.dot == 0 && !num)
	{
		if (flags.width >= 0 && flags.minus == 0)
			count += (ft_width(flags.width - 2, 0, 0) || 1)
				+ (ft_putsp("0x", 2) || 1);
		else
			count += (ft_putsp("0x", 2) || 1)
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
