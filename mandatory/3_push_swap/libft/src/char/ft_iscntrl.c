/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:23:23 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:45:03 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Check if character c is a control character.
** =========
** #1: the character to be analysed.
** =========
** Return 1 if this is the case (TRUE),
** 0 if not (FALSE).
*/

int	ft_iscntrl(int i)
{
	if ((i >= 0 && i <= 31) || i == 127)
		return (1);
	return (OK);
}
