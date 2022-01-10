/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:33:30 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:46:15 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Écrit la chaîne de caractères s sur le file descriptor donné,
** suivi d'un retour à la ligne.
** =========
** #1 : la chaîne à écrire.
** #2 : le file descriptor.
** =========
*/

void	ft_putendl_fd(const char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
