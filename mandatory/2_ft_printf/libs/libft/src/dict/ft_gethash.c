/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:45:53 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:43:23 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_gethash(char *string)
{
	unsigned int	hash;
	int				counter;

	counter = 0;
	while (*(string + counter) != '\0')
	{
		hash = *(string + counter) + (hash << 6) + (hash << 16) - hash;
		counter++;
	}
	return (hash % MAXELEMENTS);
}
