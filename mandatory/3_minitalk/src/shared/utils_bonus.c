/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienrossignol <adrienrossignol@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:59:56 by adrienrossi       #+#    #+#             */
/*   Updated: 2022/01/21 13:00:27 by adrienrossi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_minitalk.h"

static int	fisspace(int i)
{
	if (i == ' ' || i == '\t' || i == '\n' || i == '\v'
		|| i == '\f' || i == '\r')
		return (1);
	return (0);
}

static int	fisdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	nb;

	neg = 1;
	nb = 0;
	while (fisspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		neg = -1 + 0 * *str++;
	while (*str && fisdigit(*str))
	{
		nb = nb * 10 + *str++ - '0';
		if (nb > 2147483647)
			return (-1 + (neg == -1));
	}
	return (neg * nb);
}
