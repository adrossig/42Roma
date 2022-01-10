/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:22:11 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:45:03 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Check if the character c is alphanumeric.
** =========
** #1: the character to be analysed.
** =========
** Return 1 if this is the case (TRUE),
** 0 if not (FALSE).
*/

int	ft_isalnum(int i)
{
	if (ft_isdigit(i) || ft_isalpha(i))
		return (1);
	return (OK);
}
