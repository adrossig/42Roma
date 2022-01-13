/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:32:53 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:39:48 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Écrit le caractère c sur le file descriptor donné.
** =========
** #1 : le caractère à écrire.
** #2 : le file descriptor.
** =========
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
