/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:35:42 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:47:06 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

double	ft_sqrt(double nbr)
{
	int	i;

	i = 1;
	if (nbr == 0)
		return (OK);
	while ((i * i) < nbr)
		i++;
	if ((i * i) == nbr)
		return (i);
	else
		return (OK);
}
