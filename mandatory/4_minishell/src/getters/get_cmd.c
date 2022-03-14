/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:48:39 by arossign          #+#    #+#             */
/*   Updated: 2022/03/14 10:05:18 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*find_cmd(char **env_path, char *cmd, char *full_path)
{
	char *tmp;
	int i;

	i = -1;
	full_path = NULL;
	while (env_path && env_path[++i])
	{
		free(full_path);
		tmp = ft_strjoin(env_path[i], "/");
		if (tmp)
			return (NULL);
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK) == 0)
			break;
	}
	if (!env_path || !env_path[i])
	{
		free(full_path);
		return (NULL);
	}
	return (full_path);
}

static DIR *cmd_checks(t_prompt *prompt, t_list *cmd, char ***str, char *path)
{
	t_mini *n;
	DIR *dir;

	dir = NULL;
	n = cmd->content;
	if (n && n->full_cmd)
		dir = opendir(*n->full_cmd);
	if (n && n->full_cmd && ft_strchr(*n->full_cmd, '/') && !dir)
	{
		*str = ft_split(*n->full_cmd, '/');
		n->full_path = ft_strdup(*n->full_cmd);
		free(n->full_cmd[0]);
		n->full_cmd[0] = ft_strdup(str[0][ft_matrixlen(*str) - 1]);
	}
	else if (!is_builtin(n) && n && n->full_cmd && !dir)
	{
		path = minishell_getenv("PATH", prompt->env, 4);
		*str = ft_split(path, ':');
		free(path);
		n->full_path = find_cmd(*str, *n->full_cmd, n->full_path);
		if (!n->full_path || !n->full_cmd[0] || !n->full_cmd[0][0])
			error(NCMD, *n->full_cmd, 127);
	}
	return (dir);
}

void get_cmd(t_prompt *prompt, t_list *cmd, char **s, char *path)
{
	t_mini *n;
	DIR *dir;

	n = cmd->content;
	dir = cmd_checks(prompt, cmd, &s, path);
	if (!is_builtin(n) && n && n->full_cmd && dir)
		error(IS_DIR, *n->full_cmd, 126);
	else if (!is_builtin(n) && n && n->full_path && access(n->full_path, F_OK) == -1)
		error(NDIR, n->full_path, 127);
	else if (!is_builtin(n) && n && n->full_path && access(n->full_path, X_OK) == -1)
		error(NPERM, n->full_path, 126);
	if (dir)
		closedir(dir);
	ft_free_matrix(&s);
}

void *exec_cmd(t_prompt *prompt, t_list *cmd)
{
	int fd[2];

	get_cmd(prompt, cmd, NULL, NULL);
	if (pipe(fd) == - 1)
		return (error(PIPERR, NULL, 1));
	if (!check_fork(prompt, cmd, fd))
		return (NULL);
	close(fd[WRITE_END]);
	if (cmd->next && !((t_mini *)cmd->next->content)->infile)
		((t_mini *)cmd->next->content)->infile = fd[READ_END];
	else
		close(fd[READ_END]);
	if (((t_mini *)cmd->content)->infile > 2)
		close(((t_mini *)cmd->content)->infile);
	if (((t_mini *)cmd->content)->outfile > 2)
		close(((t_mini *)cmd->content)->outfile);
	return (NULL);
}
