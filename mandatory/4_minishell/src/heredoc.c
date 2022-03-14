/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:13:15 by arossign          #+#    #+#             */
/*   Updated: 2022/03/13 23:21:30 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int g_status;

char *get_hdc_str(char *str[2], size_t len, char *limit, char *warn)
{
	char *tmp;

	g_status = 0;
	while (g_status != 130 && (!str[0] || ft_strncmp(str[0], limit, len) \
		|| ft_strlen(limit) != len))
	{
		tmp = str[1];
		str[1] = ft_strjoin(str[1], str[0]);
		free(tmp);
		free(str[0]);
		str[0] = readline("> ");
		if (!str[0])
		{
			printf("%s (wanted `%s\')\n", warn, limit);
			break;
		}
		tmp = str[0];
		str[0] = ft_strjoin(str[0], "\n");
		free(tmp);
		len = ft_strlen(str[0]) - 1;
	}
	free(str[0]);
	return (str[1]);
}

int get_hdc(char *str[2], char *aux[2])
{
	int fd[2];

	if (pipe(fd) == -1)
	{
		error(PIPERR, NULL, 1);
		return (-1);
	}
	close(fd[WRITE_END]);
	str[1] = get_hdc_str(str, 0, aux[0], aux[1]);
	write(fd[READ_END], str[1], ft_strlen(str[1]));
	if (g_status == 130)
	{
		close(fd[READ_END]);
		return (-1);
	}
	return (fd[READ_END]);
}
