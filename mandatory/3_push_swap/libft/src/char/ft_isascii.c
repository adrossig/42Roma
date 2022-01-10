/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:22:48 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:45:03 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Checks if the c character is a 7-bit unsigned char,
** entering the character set of the ASCII table.
** =========
** #1: the character to be analysed.
** =========
** Return 1 if this is the case (TRUE),
** 0 if not (FALSE).
*/

int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	return (OK);
}
