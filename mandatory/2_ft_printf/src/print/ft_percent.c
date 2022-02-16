/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:04:56 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/16 10:51:08 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/**
 * Prints a percent sign.
 *
 * @param flags The flags to use for the percent sign.
 *
 * @returns The number of characters printed.
 */
int	ft_percent(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count = count + ft_putsp("%", 1, flags.fd);
	count = count + ft_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count = count + ft_putsp("%", 1, flags.fd);
	return (count);
}
