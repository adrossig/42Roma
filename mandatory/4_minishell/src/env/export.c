/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:45:58 by arossign          #+#    #+#             */
/*   Updated: 2022/03/14 09:58:20 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	minishell_export(t_prompt *prompt)
{
	int		i[2];
	int		pos;
	char	**av;

	av = ((t_mini *)prompt->cmds->content)->full_cmd;
	if (ft_matrixlen(av) >= 2)
	{
		i[0] = 1;
		while (av[i[0]])
		{
			pos = env(av[i[0]], prompt->env, i);
			if (pos == 1)
			{
				free(prompt->env[i[1]]);
				prompt->env[i[1]] = ft_strdup(av[i[0]]);
			}
			else if (!pos)
				prompt->env = ft_extend_matrix(prompt->env, av[i[0]]);
			i[0]++;
		}
	}
	return (0);
}
