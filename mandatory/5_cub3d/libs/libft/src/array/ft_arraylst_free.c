/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylst_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:31:46 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:37:58 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_arraylst_free(t_array *arraylist)
{
	if (arraylist != NULL)
	{
		free(arraylist->data);
		free(arraylist);
	}
}
