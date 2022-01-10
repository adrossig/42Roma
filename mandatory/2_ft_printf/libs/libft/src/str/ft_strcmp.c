/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:36:46 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:31:22 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned int	i;

	i = 0;
	while (*(str1 + i) == *(str2 + i) && *(str1 + i))
		i++;
	return (((unsigned char)*(str1 + i)) - ((unsigned char)*(str2 + i)));
}
