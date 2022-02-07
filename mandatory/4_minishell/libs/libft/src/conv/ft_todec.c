/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_todec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:00:56 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 13:18:16 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	value(char c)
{
	if (c >= '0' && c <= '9')
		return ((int)c - '0');
	else
		return ((int)c - 'A' + 10);
}

int	ft_todec(char *str, int base)
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
