/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:37:32 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:57:23 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Duplicates a string.
 *
 * @param str The string to duplicate.
 *
 * @returns A pointer to the duplicated string.
 */
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
