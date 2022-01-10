/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:32:43 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 18:04:59 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putuint_base_fd(uintmax_t n, int base, int ch, int fd)
{
	if (base < 0 || fd < 0)
		return ;
	if (n >= (unsigned)base)
	{
		ft_putuint_base_fd(n / base, base, ch, fd);
		ft_putuint_base_fd(n % base, base, ch, fd);
	}
	else
		ft_putchar_fd((n + '0') * (base <= 10 || n < 10)
			+ (n % 10 + ch) * (n >= 10), fd);
}
