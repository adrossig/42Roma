/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_todec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:00:56 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 23:58:25 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Converts a number of any type into a decimal number.
** =======
** #1: the number to be converted.
** #2: the basis of conversion (ex: base 10).
** =======
** Returns the result of the conversion as an integer long type.
*/

static int	value(char c)
{
	if (c >= '0' && c <= '9')
		return ((int)c - '0');
	else
		return ((int)c - 'A' + 10);
}

int			ft_todec(char *str, int base)
{
	int	lenght;
	int	power;
	int	num;
	int	i;

	if (!str)
		return (OK);
	lenght = ft_strlen(str);
	power = 1;
	num = 0;
	i = lenght - 1;
	while (i >= 0)
	{
		num += value(*(str + i)) * power;
		power = power * base;
		i--;
	}
	return (num);
}
