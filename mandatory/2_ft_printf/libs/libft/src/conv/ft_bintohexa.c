/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintohexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:46:52 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:50:00 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_bintohexa(int binary)
{
	int	hexadecimal;
	int	i;

	hexadecimal = 0;
	i = 1;
	while (binary != 0)
	{
		hexadecimal = hexadecimal + binary % 10 * i;
		i = i * 2;
		binary = binary / 10;
	}
	return (hexadecimal);
}
