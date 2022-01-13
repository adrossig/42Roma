/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:32:37 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:39:15 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_power(int nbr, int power)
{
	if (nbr < 0)
		return (OK);
	if (nbr == 0)
		return (1);
	return (nbr * ft_power(nbr, power - 1));
}
