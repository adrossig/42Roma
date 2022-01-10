/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_formatted_nbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:55:07 by adrossig          #+#    #+#             */
/*   Updated: 2021/01/14 14:15:45 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Imprime une chaîne de caractère (post-itoa), après formatage.
** =========
** #1 : un format.
** #2 : une chaîne de caractère.
** =========
** Retourne le nombre total de caractères imprimés,
** -1 en cas d'erreur.
*/

int	ft_put_formatted_nbr(t_format format, char *number)
{
	int		len;
	int		p;
	char	*precised;
	char	*with_width;

	len = -1;
	len = ft_strlen(number);
	if (number[0] == '-')
		len -= 1;
	if (format.precision <= len)
		p = len;
	else
		p = format.precision;
	precised = ft_int_add_precision(number, p);
	free(number);
	len = ft_strlen(precised);
	if (format.width <= len)
		format.width = len;
	with_width = ft_int_add_width(format, precised);
	free(precised);
	len = ft_strlen(with_width);
	ft_putstr_fd(with_width, format.fd);
	free(with_width);
	return (len);
}
