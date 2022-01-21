/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 10:45:44 by adrossig          #+#    #+#             */
/*   Updated: 2022/01/20 15:03:15 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Allocates (with malloc(3)) and returns a chain of
** characters representing an integer n received as argument.
** Negative numbers must be handled.
** =======
** #1: the integer to be converted.
** #2: the basis for conversion.
** =======
** Returns the character string representing the integer,
** NULL if the allocation fails.
*/

char	*ft_itoa_base_custom(u_int64_t nbr, uintmax_t base)
{
	static char	hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F'};
	char		*str;
	uintmax_t	converted_nbr[64];
	uintmax_t	n;
	int64_t		i;

	if (nbr == 0)
		return (ft_strdup("0"));
	i = 0;
	n = (uintmax_t)nbr;
	while (n > 0)
	{
		converted_nbr[i++] = n % (uintmax_t)base;
		n /= (uintmax_t)base;
	}
	str = (char *)malloc(sizeof(char *) * (uintmax_t)i);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i--;
	while (i >= 0)
		str[n++] = hex[converted_nbr[i--]];
	return (str);
}
