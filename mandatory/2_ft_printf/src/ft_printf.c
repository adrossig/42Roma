/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:34:49 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/16 10:42:01 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * Handles the input arguments for ft_printf.
 *
 * @param format The format string.
 * @param args The arguments to the format string.
 *
 * @returns The number of characters printed.
 */
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

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	const char	*str;
	int			count;

	count = 0;
	str = ft_strdup(format);
	if (!str)
		return (0);
	va_start(args, format);
	count += ft_handling_input(str, args, fd);
	va_end(args);
	free((char *)str);
	return (count);
}
