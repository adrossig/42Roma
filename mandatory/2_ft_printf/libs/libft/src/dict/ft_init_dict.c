/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:41:15 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:43:10 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_dictionary	*create_dict(void)
{
	t_dictionary	*locma;
	int				i;

	locma = malloc(sizeof(t_dictionary));
	if (!(locma))
		return (NULL);
	else
	{
		locma->nbr = 0;
		i = 0;
		while (i < MAXELEMENTS)
		{
			locma->elements[i] = NULL;
			i++;
		}
		return (locma);
	}
}
