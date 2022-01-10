/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatooctal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:02:55 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:49:07 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long long	ft_hexatooctal(char *hex)
{
	int	temp;
	int	result;

	if (!hex)
		return (OK);
	temp = ft_todec(hex, 16);
	result = ft_dectooctal(temp);
	return (result);
}
