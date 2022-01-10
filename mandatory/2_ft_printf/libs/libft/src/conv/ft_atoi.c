/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:52:40 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 18:05:25 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_isspc(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

static int	ft_isdig(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	nat;
	int			ichara;

	i = 0;
	nat = 0;
	ichara = 1;
	while (ft_isspc(*(str)))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		ichara = -1 + 0 * *str++;
	while (*str && ft_isdig(*str))
	{
		nat = nat * 10 + *str++ - '0';
		if (nat > 922337203685477580)
			return (-1 + (ichara == -1));
	}
	return ((int)(nat * ichara));
}
