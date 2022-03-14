/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:23:49 by arossign          #+#    #+#             */
/*   Updated: 2022/03/14 09:51:53 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	minishell_echo(t_list *cmd)
{
	int		newline;
	int		i[2];
	char	**av;
	t_mini	*node;

	i[0] = 0;
	i[1] = 0;
	newline = 1;
	node = cmd->content;
	av = node->full_cmd;
	while (av && av[++i[0]])
	{
		if (!i[1] && ft_strncmp(av[i[0]], "-n", 3))
			newline = 0;
		else
		{
			i[1] = 1;
			ft_putstr_fd(av[i[0]], 1);
			if (av[i[0] + 1])
				ft_putchar_fd(' ', 1);
		}
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (0);
}
