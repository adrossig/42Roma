/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uimax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 10:46:16 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:37:30 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Allocates (with malloc(3)) and returns a chain of
** characters representing an integer nb with the largest possible range
** received in argument.
** Negative numbers must be handled.
** =======
** #1: the integer to be converted.
** =======
** Returns the character string representing the integer,
** NULL if the allocation fails.
*/

char	*ft_itoa_uimax(uintmax_t nb)
{
	char	*ret;
	int		len;

	len = ft_int_length_uimax(nb);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	while (len-- > 0)
	{
		ret[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (ret);
}
