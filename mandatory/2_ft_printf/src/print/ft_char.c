/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:57:30 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 17:56:58 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count = ft_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}
