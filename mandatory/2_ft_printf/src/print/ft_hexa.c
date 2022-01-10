/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:09:06 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 17:57:10 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_hexa_input(char *hex, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
	{
		count = count + ft_width(flags.dot - 1, ft_strlen(hex) - 1, 1);
	}
	count = count + ft_putsp(hex, ft_strlen(hex));
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
		count = count + ft_width(flags.width, 0, 0);
	}
	else
	{
		count = count + ft_width(flags.width, ft_strlen(hex), flags.zero);
	}
	if (flags.minus == 0)
		count = count + ft_hexa_input(hex, flags);
	return (count);
}

int	ft_hexa(unsigned int number, int lowercase, t_flags flags)
{
	char	*hex;
	int		count;

	number = (unsigned int)(4294967295 + 1 + number);
	count = 0;
	if (flags.dot == 0 && number == 0)
	{
		count = count + ft_width(flags.width, 0, 0);
		return (count);
	}
	hex = ft_utl_base((unsigned long long)number, 16);
	if (lowercase == 1)
		hex = ft_tolower_str(hex);
	count = count + ft_put_hexa(hex, flags);
	free(hex);
	return (count);
}
