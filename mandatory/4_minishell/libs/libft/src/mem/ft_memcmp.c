/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:31:09 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:31:12 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (OK);
	while (i < (n - 1)
		&& *((unsigned char *)(s1 + i)) == *((unsigned char *)(s2 + i)))
		i++;
	return (*((unsigned char *)(s1 + i)) - *((unsigned char *)(s2 + i)));
}
