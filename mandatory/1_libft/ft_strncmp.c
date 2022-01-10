/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:40:34 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 11:39:16 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t i)
{
	unsigned int	j;

	j = 0;
	if (i == 0)
		return (0);
	while ((str1[j] == str2[j]) && str1[j] && (--i))
		++j;
	return ((unsigned char)str1[j] - (unsigned char)str2[j]);
}
