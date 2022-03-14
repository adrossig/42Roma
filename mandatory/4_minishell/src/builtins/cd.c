/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:15:42 by arossign          #+#    #+#             */
/*   Updated: 2022/03/13 17:23:43 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int g_status;

int	minishell_cd(t_prompt *prompt)
{
	char **str[2];
	char *aux;
	DIR	*dir;

	g_status = 0;
	str[0] = ((t_mini *)prompt->cmds->content)->full_cmd;
	aux = minishell_getenv("HOME", prompt->env, 4);
	if (!aux)
		aux = ft_strdup("");
	str[1] = ft_extend_matrix(NULL, aux);
	free(aux);
	aux = getcwd(NULL, 0);
	str[1] = ft_extend_matrix(str[1], aux);
	free(aux);
	dir = cd_error(str);
	if (str[0][1] && dir)
		closedir(dir);
	if (!g_status)
		prompt->env = minishell_setenv("OLDPWD", str[1][1], prompt->env, 6);
	aux = getcwd(NULL, 0);
	str[1] = ft_extend_matrix(str[1], aux);
	free(aux);
	prompt->env = minishell_setenv("PWD", str[1][2], prompt->env, 3);
	ft_free_matrix(&str[1]);
	return (g_status);
}
