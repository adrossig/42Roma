/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:28:34 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/28 13:12:08 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** is_there_line(1)
** =========
*/

int	is_there_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
** find_char_index(1)
** =========
*/

int	find_char_index(char *s, char c, char d)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == d)
			return (i);
		i++;
	}
	return (-1);
}

/*
** free_and_return_null(1)
** =========
*/

void	free_and_return_null(char **s)
{
	if (*s && s)
	{
		free(*s);
		*s = NULL;
	}
}

int	final_step(int fdb, char ***line, char **kpr)
{
	char	*tmp;

	if ((fdb < 0))
	{
		**line = ft_substr(*kpr, 0, ft_strlen(*kpr));
		free_and_return_null(kpr);
		return (0);
	}
	**line = ft_substr(*kpr, 0, fdb);
	tmp = ft_substr(*kpr, (fdb + 1), ft_strlen(*kpr) - (fdb + 1));
	free_and_return_null(kpr);
	*kpr = tmp;
	if (*line)
		return (1);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	char		*temp;
	static char	*kpr[OPEN_MAX];
	int			line_exist;
	int			fdb;

	if ((fd < 0) || (read(fd, NULL, 0) < 0) || (BUFFER_SIZE <= 0) || !line)
		return (-1);
	kpr[fd] = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!(kpr[fd]))
		return (-1);
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line_exist = is_there_line(kpr[fd]);
	fdb = read(fd, buff, BUFFER_SIZE);
	while ((line_exist == 0) && fdb > 0)
	{
		buff[fdb] = '\0';
		temp = ft_strjoin(kpr[fd], buff);
		free_and_return_null(&kpr[fd]);
		kpr[fd] = temp;
		line_exist = is_there_line(kpr[fd]);
	}
	free_and_return_null(&buff);
	fdb = find_char_index(kpr[fd], '\n', '\0');
	return (final_step(fdb, &line, &kpr[fd]));
}
