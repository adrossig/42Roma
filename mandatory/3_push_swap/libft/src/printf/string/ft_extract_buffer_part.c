/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_buffer_part.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:23:03 by adrossig          #+#    #+#             */
/*   Updated: 2021/01/14 14:16:14 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Alloue et crée une chaîne de caractères
** dans laquelle sont copiés n caractères de la chaîne source.
** =========
** #1 : le nombre de caractères à extraire.
** #2 : la chaîne dans laquelle extraire le(s) caractère(s).
** =========
** Retourne la nouvelle chaîne de caractères créée,
** NULL en cas d'erreur.
*/

char	*ft_extract_buffer_part(int precision, char *buffer)
{
	int		i;
	char	*ret;

	i = 0;
	if (precision == -1)
		precision = (int)ft_strlen(buffer);
	ret = (char *)malloc(sizeof(char) * (precision + 1));
	if (ret == NULL)
		return (NULL);
	while (i < precision)
	{
		ret[i] = buffer[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
