/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:57:38 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/16 10:49:03 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * Checks if a character is a conversion specifier.
 *
 * @param c The character to check.
 *
 * @returns True if the character is a conversion specifier.
 */
int	ft_isconversion(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

/**
 * Checks if a character is a flag.
 *
 * @param c The character to check.
 *
 * @returns True if the character is a flag, false otherwise.
 */
int	ft_isflag(int c)
{
	return ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '));
}

/**
 * Prints a string to the console.
 *
 * @param str The string to print.
 * @param precision The maximum number of characters to print.
 *
 * @returns The number of characters printed.
 */
int	ft_putsp(char *str, int precision, int fd)
{
	int	i;

	i = 0;
	while (str[i] && i < precision)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	return (i);
}
