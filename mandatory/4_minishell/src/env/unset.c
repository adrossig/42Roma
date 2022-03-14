/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:30:46 by arossign          #+#    #+#             */
/*   Updated: 2022/03/13 20:44:11 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	minishell_unset(t_prompt *prompt)
{
	char	**av;
	char	*aux;
	int		tmp[2];

	tmp[0] = 0;
	av = ((t_mini *)prompt->cmds->content)->full_cmd;
	if (ft_matrixlen(av) >= 2)
	{
		while (av[++tmp[0]])
		{
			if (av[tmp[0]][ft_strlen(av[tmp[0]]) - 1] != '=')
			{
				aux = ft_strjoin(av[tmp[0]], "=");
				free(av[tmp[0]]);
				av[tmp[0]] = aux;
			}
			if (env(av[tmp[0]], prompt->env, tmp))
				ft_matrix_replace_in(&prompt->env, NULL, tmp[1]);
		}
	}
	return (0);
}
