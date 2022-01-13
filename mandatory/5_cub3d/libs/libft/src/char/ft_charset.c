/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:55:48 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:37:45 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Check if the character charset is in the string str.
** =========
** #1: the string to analized.
** #2: the character to find.
** =========
** Return 1 if the charset is find (TRUE),
** 0 if not (FALSE).
*/

int	ft_charset(char str, char *charset)
{
	int	i;

	i = 0;
	while (*(charset + i))
	{
		if (str == *(charset + i))
			return (1);
		i++;
	}
	return (OK);
}
