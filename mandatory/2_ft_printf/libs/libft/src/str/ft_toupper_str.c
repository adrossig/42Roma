/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:02:40 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 18:02:29 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_toupper_str(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		*(str + i) = ft_toupper(*(str + i));
		i++;
	}
	return (str);
}
