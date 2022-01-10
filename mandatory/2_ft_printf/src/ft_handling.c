/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:40:01 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 18:01:37 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_handling(int c, t_flags flags, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_char(va_arg(args, int), flags);
	else if (c == '%')
		count = count + ft_percent(flags);
	else if (c == 'p')
		count = count + ft_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 's')
		count = count + ft_string(va_arg(args, char *), flags);
	else if (c == 'i' || c == 'd')
		count = count + ft_int(va_arg(args, int), flags);
	else if (c == 'x')
		count = count + ft_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count = count + ft_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == 'u')
		count += ft_uint((unsigned int)va_arg(args, unsigned int), flags);
	return (count);
}

int	ft_handling_input(const char *str, va_list args)
{
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	while (!0)
	{
		flags = ft_initialize();
		if (!str[i])
			break ;
		else if (str[i] != '%')
			count = count + ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_parse(str, ++i, &flags, args);
			if (ft_isconversion(str[i]))
				count = count + ft_handling((char)flags.type, flags, args);
			else if (str[i])
				count = count + ft_putchar(str[i]);
		}
		i++;
	}
	return (count);
}
