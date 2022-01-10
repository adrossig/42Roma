/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element_label.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:57:28 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:45:13 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_get_element_label(t_dictionary *dict, char *string)
{
	int	index;

	index = ft_gethash(string);
	if (dict->elements[index])
		return (dict->elements[index]);
	return (NULL);
}
