/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:54:18 by arossign          #+#    #+#             */
/*   Updated: 2022/02/17 16:54:19 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int g_fds[2][2];

int	ft_strchars_i(char *str, char *set)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (ft_strchr(str, set[i]))
			return (i);
		i++;
	}
	return (-1);
}
