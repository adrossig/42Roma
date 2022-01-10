/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:55:28 by adrossig          #+#    #+#             */
/*   Updated: 2021/01/14 14:17:03 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Imprime sur stdout la chaîne de caractères
** passée en premier argument en suivant les indications
** de formatage si elles existent.
** =========
** #1 : la chaîne de caractère constante,
**		qui contient (ou non) une (des) indication(s) de formatage.
** #(...) : le(s) élément(s) dans l'ordre à formater.
** =========
** Retourne le nombre de caractères imrimés,
** sans compter l'octer nul final.
*/

int	ft_printf(const char *str, ...)
{
	t_position	position;
	t_format	format;
	int			ret_printed;
	size_t		len;
	va_list		ap;

	format.fd = 1;
	position.index = 0;
	position.pos = 0;
	ret_printed = 0;
	va_start(ap, str);
	ft_arg(str, &position, ap, &ret_printed);
	va_end(ap);
	len = position.index - position.pos;
	write(format.fd, (str + position.pos), len);
	ret_printed += len;
	return (ret_printed);
}

/*
** Imprime sur le fd choisi la chaîne de caractères
** passée en premier argument en suivant les indications
** de formatage si elles existent.
** =========
** #1 : la sortie sur laquel ft_printf sera afficher
** #2 : la chaîne de caractère constante,
**		qui contient (ou non) une (des) indication(s) de formatage.
** #(...) : le(s) élément(s) dans l'ordre à formater.
** =========
** Retourne le nombre de caractères imrimés,
** sans compter l'octer nul final.
*/

int	ft_dprintf(int fd, const char *str, ...)
{
	t_position	position;
	int			ret_printed;
	size_t		len;
	va_list		ap;
	t_format	format;

	format.fd = fd;
	position.index = 0;
	position.pos = 0;
	ret_printed = 0;
	va_start(ap, str);
	ft_arg(str, &position, ap, &ret_printed);
	va_end(ap);
	len = position.index - position.pos;
	write(format.fd, (str + position.pos), len);
	ret_printed += len;
	return (ret_printed);
}
