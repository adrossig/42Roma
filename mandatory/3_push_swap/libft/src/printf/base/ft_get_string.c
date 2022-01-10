/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:15:15 by adrossig          #+#    #+#             */
/*   Updated: 2021/01/14 14:08:10 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Imprime les parties de la chaîne de caractères principale de ft_printf()
** qui ne nécessitent pas de conversion.
** =========
** #1 : la chaîne de caractères, premier argument de ft_printf().
** #2 : un pointeur sur la position actuelle dans str.
** =========
** Retourne le nombre de caractère imprimés.
*/

int	ft_get_string(const char *str, size_t *ptr_pos)
{
	size_t		j;
	size_t		k;
	char		*line;
	t_format	format;

	j = *ptr_pos;
	k = 0;
	while (str[*ptr_pos] != '%')
	{
		*ptr_pos += 1;
		k++;
	}
	*ptr_pos += 1;
	line = malloc(sizeof(char) * (k + 1));
	if (line == NULL)
		return (KO);
	k = 0;
	while (str[j] != '%')
		line[k++] = str[j++];
	ptr_pos += 1;
	write(format.fd, line, k);
	free(line);
	return (k);
}
