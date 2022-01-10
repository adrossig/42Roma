/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:39:34 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:46:26 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Calcule la longueur d'une chaîne de caractères.
** =========
** #1 : une chaîne de caractère.
** =========
** Retourne le nombre de caractères dans s.
*/

size_t	ft_strlen(const char *str)
{
	const char	*dest;

	dest = str;
	while (*dest)
		++dest;
	return (dest - str);
}
