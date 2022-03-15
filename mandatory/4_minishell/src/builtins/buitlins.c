/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitlins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:04:10 by arossign          #+#    #+#             */
/*   Updated: 2022/03/14 10:25:26 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

int	builtin(t_prompt *prompt, t_list *cmd, int *is_exist, int n)
{
	char	**tmp;

	while (cmd)
	{
		tmp = ((t_mini *)cmd->content)->full_cmd;
		n = 0;
		if (tmp)
			n = ft_strlen(*tmp);
		if (tmp && !ft_strncmp(*tmp, "exit", n) && n == 4)
			g_status = minishell_exit(cmd, is_exist);
		else if (!cmd->next && tmp && !ft_strncmp(*tmp, "cd", n) && n == 2)
			g_status = minishell_cd(prompt);
		else if (!cmd->next && tmp && !ft_strncmp(*tmp, "export", n) && n == 6)
			g_status = minishell_export(prompt);
		else if (!cmd->next && tmp && !ft_strncmp(*tmp, "unset", n) && n == 5)
			g_status = minishell_unset(prompt);
		else
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
			exec_cmd(prompt, cmd);
		}
		cmd = cmd->next;
	}
	return (g_status);
}

int	is_builtin(t_mini *n)
{
	int	nbr;

	if (!n->full_cmd)
		return (0);
	if ((n->full_cmd && ft_strchr(*n->full_cmd, '/')) || (n->full_path && \
		!ft_strchr(n->full_path, '/')))
		return (0);
	nbr = ft_strlen(*n->full_cmd);
	if (!ft_strncmp(*n->full_cmd, "pwd", nbr) && nbr == 3)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "env", nbr) && nbr == 3)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "cd", nbr) && nbr == 2)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "export", nbr) && nbr == 6)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "unset", nbr) && nbr == 5)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "echo", nbr) && nbr == 4)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "exit", nbr) && nbr == 4)
		return (1);
	return (0);
}

void	child_builtin(t_prompt *prompt, t_mini *n, int len, t_list *cmd)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!is_builtin(n) && n->full_cmd)
		execve(n->full_path, n->full_cmd, prompt->env);
	else if (n->full_cmd && !ft_strncmp(*n->full_cmd, "pwd", len) \
		&& len == 3)
		g_status = minishell_pwd();
	else if (is_builtin(n) && n->full_cmd && \
		!ft_strncmp(*n->full_cmd, "echo", len) && len == 4)
		g_status = minishell_echo(cmd);
	else if (is_builtin(n) && n->full_cmd && \
		!ft_strncmp(*n->full_cmd, "env", len) && len == 3)
	{
		ft_matrix_putfd(prompt->env, 1);
		g_status = 0;
	}
}
