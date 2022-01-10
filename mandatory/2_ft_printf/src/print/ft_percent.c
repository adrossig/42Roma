/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:04:56 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 17:57:04 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_percent(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count = count + ft_putsp("%", 1);
	count = count + ft_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count = count + ft_putsp("%", 1);
	return (count);
}
