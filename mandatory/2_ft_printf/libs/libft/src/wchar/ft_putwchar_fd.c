/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:01:43 by arossign          #+#    #+#             */
/*   Updated: 2022/01/11 11:01:44 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putwchar_fd(wchar_t c, int fd)
{
	if (c <= 0x7F)
		ft_putchar_fd(c, fd);
	else if (c <= 0x7FF)
	{
		ft_putchar_fd((c >> 6) + 0xC0, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar_fd((c >> 12) + 0xE0, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar_fd((c >> 18) + 0xF0, fd);
		ft_putchar_fd(((c >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
}
