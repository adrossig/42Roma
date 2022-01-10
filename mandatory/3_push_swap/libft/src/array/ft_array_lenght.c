/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_lenght.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:15:45 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:44:37 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_array_lenght(void **array)
{
	ssize_t	lenght;

	lenght = -1;
	while (*(array + lenght))
		++lenght;
	return (lenght);
}
