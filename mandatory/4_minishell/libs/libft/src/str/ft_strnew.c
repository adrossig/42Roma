/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:41:36 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:33:03 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*locma;

	locma = (char *)malloc(sizeof(char) * (size + 1));
	if (!(locma))
		return (NULL);
	ft_bzero(locma, size);
	return (locma);
}
