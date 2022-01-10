/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:40:47 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:31:42 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t i)
{
	unsigned int	j;

	j = 0;
	while ((*(src + j) != '\0') && j < i)
	{
		*(dest + j) = *(src + j);
		j++;
	}
	while (j < i)
	{
		*(dest + j) = '\0';
		j++;
	}
	return (dest);
}
