/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:10:54 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:44:47 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Allocates (with malloc(3)) and returns a chain of
** characters representing an unsigned integer n received as argument.
** =======
** #1: the integer to be converted.
** #2: the specifier indicating whether the base is in SHIFT or MIN.
** =======
** Returns the character string representing the integer,
** NULL if the allocation fails.
*/

char	*ft_hexitoa(unsigned int n, char c)
{
	char	*str;
	char	*base;
	size_t	len;

	str = NULL;
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	len = ft_hexintlen(n);
	if (len > 1)
		len -= 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		str[len] = '\0';
		while (len > 0)
		{
			str[len - 1] = base[(n % 16)];
			len--;
			n = n / 16;
		}
	}
	return (str);
}

/*
** Allocates (with malloc(3)) and returns a chain of
** characters representing an unsigned long n received as an argument.
** =======
** #1: the integer to be converted.
** #2: the specifier indicating whether the base is in SHIFT or MIN.
** =======
** Returns the character string representing the integer,
** NULL if the allocation fails.
*/

char	*ft_long_hexitoa(unsigned long n, char c)
{
	char	*str;
	char	*base;
	size_t	len;

	str = NULL;
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	len = ft_long_hexintlen(n);
	if (len > 1)
		len -= 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		str[len] = '\0';
		while (len > 0)
		{
			str[len - 1] = base[(n % 16)];
			len--;
			n = n / 16;
		}
	}
	return (str);
}
