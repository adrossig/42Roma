/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uimax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 10:46:16 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 13:17:16 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_itoa_uimax(uintmax_t nb)
{
	char	*ret;
	int		len;

	len = ft_int_length_uimax(nb);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!(ret))
		return (NULL);
	ret[len] = '\0';
	while (len-- > 0)
	{
		ret[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (ret);
}
