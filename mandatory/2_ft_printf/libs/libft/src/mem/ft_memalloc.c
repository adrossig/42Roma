/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:08 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:30:30 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = malloc(sizeof(memory) * size);
	if (!(memory))
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
