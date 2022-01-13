/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:34:39 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 23:49:33 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Écrit la chaîne de caractères str.
** =========
** #1 : la chaîne à écrire.
** =========
*/

void	ft_putstr(const char *str)
{
	if (str != NULL)
		write(1, str, ft_strlen(str));
}
