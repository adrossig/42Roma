/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:25:05 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:45:03 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Check if the character c is a space.
** =========
** #1: the character to be analysed.
** =========
** Return 1 if this is the case (TRUE),
** 0 if not (FALSE).
*/

int	ft_isspace(int i)
{
	if (i == ' ' || i == '\t' || i == '\n' || i == '\v'
		|| i == '\f' || i == '\r')
		return (1);
	return (OK);
}
