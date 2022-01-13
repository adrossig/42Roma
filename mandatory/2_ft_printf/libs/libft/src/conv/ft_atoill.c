/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:02:54 by arossign          #+#    #+#             */
/*   Updated: 2022/01/11 11:02:55 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	sign_or_not(const char *nptr)
{
	int	u;
	int	i;

	u = 0;
	i = 0;
	while (ft_isdigit(nptr[i]) == 0)
	{
		if (nptr[i] == '+' || nptr[i] == '-')
			u++;
		i++;
	}
	return (u);
}

static int	invisible_or_not(const char nptr)
{
	int	u;

	u = 0;
	if (nptr == '\n' || nptr == '\t' || nptr == ' ' || nptr == '\r'
		|| nptr == '\v' || nptr == '\f')
		u++;
	return (u);
}

long long	ft_atoill(const char *nptr)
{
	int			i;
	long long	nbr;
	int			sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (invisible_or_not(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+')
		i++;
	if (nptr[i] == '-' && sign_or_not(nptr) == 1)
	{
		sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr = (nbr * 10) + nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
}
