/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:34:49 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 17:33:47 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*str;
	int			count;

	count = 0;
	str = ft_strdup(format);
	if (!str)
		return (0);
	va_start(args, format);
	count += ft_handling_input(str, args);
	va_end(args);
	free((char *)str);
	return (count);
}
