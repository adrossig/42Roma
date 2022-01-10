/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:29:22 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 12:06:23 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*liste;

	liste = NULL;
	liste = malloc(sizeof(t_list));
	if (!(liste))
		return (NULL);
	liste->content = content;
	liste->next = NULL;
	return (liste);
}
