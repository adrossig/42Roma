/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:52:40 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:44:47 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Converts the beginning of the pointed chain into its entirety.
** =======
** #1: A pointer to a string of characters.
** =======
** Returns the result of the conversion as an integer of type int.
*/

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
		else
			sign *= 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - '0');
	return (sign * nb);
}
