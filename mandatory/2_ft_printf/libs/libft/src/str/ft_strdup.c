/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:37:32 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 16:40:27 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (*(str + len) != '\0')
		len++;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (*(str + i) != '\0')
	{
		*(ptr + i) = *(str + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
