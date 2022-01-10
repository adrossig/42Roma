/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:25:38 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 11:30:53 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char	*ft_itoa_bis(int count, int sign, int div, long nb)
{
	char	*s;
	long	res;
	int		i;

	res = 0;
	i = 0;
	s = malloc(sizeof(char) * (count + 1 + sign + 1));
	if (!(s))
		return (NULL);
	if (sign == 1)
		s[i++] = '-';
	while (div > 0)
	{
		res = (nb / div) % 10;
		s[i++] = res + 48;
		div = div / 10;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		div;
	int		count;
	int		sign;
	long	nb;

	div = 1;
	sign = 0;
	count = 0;
	nb = (long)n;
	if (nb < 0)
	{
		sign++;
		nb *= -1;
	}
	while (nb / div >= 10)
	{
		div = div * 10;
		count++;
	}
	return (ft_itoa_bis(count, sign, div, nb));
}
