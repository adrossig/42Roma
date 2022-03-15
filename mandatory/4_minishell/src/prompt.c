/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:41:03 by arossign          #+#    #+#             */
/*   Updated: 2022/03/15 15:14:05 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_status;

static char	*get_home(t_prompt prompt)
{
	char	*temp;
	char	*pwd;
	char	*home;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = ft_strdup("ø ");
	home = minishell_getenv("HOME", prompt.env, 4);
	if (home && home[0] && ft_strnstr(pwd, home, ft_strlen(pwd)))
	{
		temp = pwd;
		pwd = ft_strjoin("~", &pwd[ft_strlen(home)]);
		free(temp);
	}
	free(home);
	home = ft_strjoin(BLUE, pwd);
	free(pwd);
	pwd = ft_strjoin(home, " ");
	free(home);
	home = ft_strjoin(" ", pwd);
	free(pwd);
	pwd = ft_strjoin(home, DEFAULT);
	free(home);
	return (pwd);
}

static char	*get_user(t_prompt prompt)
{
	char	**user;
	char	*tmp1;
	char	*tmp2;

	user = NULL;
	tmp2 = NULL;
	exec_custom(&user, "/usr/bin/whoami", "whoami", prompt.env);
	if (!user)
		user = ft_extend_matrix(user, "guest");
	if (!ft_strncmp(user[0], "root", 4))
		tmp2 = ft_strjoin(NULL, RED);
	else if ((int)(user[0][0]) % 5 == 0)
		tmp2 = ft_strjoin(NULL, CYAN);
	else if ((int)(user[0][0]) % 5 == 1)
		tmp2 = ft_strjoin(NULL, GREY);
	else if ((int)(user[0][0]) % 5 == 2)
		tmp2 = ft_strjoin(NULL, GREEN);
	else if ((int)(user[0][0]) % 5 == 3)
		tmp2 = ft_strjoin(NULL, MAGENTA);
	else
		tmp2 = ft_strjoin(NULL, YELLOW);
	tmp1 = ft_strjoin(tmp2, *user);
	free(tmp2);
	ft_free_matrix(&user);
	return (tmp1);
}

char	*get_prompt(t_prompt prompt)
{
	char	*tmp1;
	char	*tmp2;
	char	*aux;

	tmp1 = get_user(prompt);
	tmp2 = ft_strjoin(tmp1, "@minishell");
	free(tmp1);
	aux = get_home(prompt);
	tmp1 = ft_strjoin(tmp2, aux);
	free(aux);
	free(tmp2);
	if (!g_status || g_status == -1)
		tmp2 = ft_strjoin(tmp1, BLUE);
	else
		tmp2 = ft_strjoin(tmp1, RED);
	free(tmp1);
	tmp1 = ft_strjoin(tmp2, "$");
	free(tmp2);
	tmp2 = ft_strjoin(tmp1, DEFAULT);
	free(tmp1);
	return (tmp2);
}
