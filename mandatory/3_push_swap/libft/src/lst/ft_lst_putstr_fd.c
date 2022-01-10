/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:51:05 by adrossig          #+#    #+#             */
/*   Updated: 2020/10/28 18:05:46 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lst_putstr_fd(t_list *elem, int fd)
{
	if (!elem)
		return ;
	else
		ft_putstr_fd((char *)elem->content, fd);
}
