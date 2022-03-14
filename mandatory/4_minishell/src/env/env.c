/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:42:48 by arossign          #+#    #+#             */
/*   Updated: 2022/03/14 09:57:55 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env(char *av, char **env, int i[2])
{
	int pos;

	i[1] = 0;
	pos = ft_strchr_index(av, '=');\
	if (pos == -1)
		return (-1);
	while (env[i[1]])
	{
		if (!ft_strncmp(env[i[1]], av, pos + 1))
			return (1);
		i[1]++;
	}
	return (0);
}
