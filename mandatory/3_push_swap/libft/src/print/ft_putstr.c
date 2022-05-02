/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:34:39 by adrossig          #+#    #+#             */
/*   Updated: 2022/04/28 13:17:11 by arossign         ###   ########.fr       */
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
	int i;

	i = 0;
	while(str[i])
		i++;
	write(1, str, i);
}
