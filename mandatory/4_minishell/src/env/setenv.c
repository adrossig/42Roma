/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:00:11 by arossign          #+#    #+#             */
/*   Updated: 2022/03/14 10:00:31 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**minishell_setenv(char *var, char *value, char **env, int nbr)
{
	int		i[2];
	char	*aux[2];

	if (nbr < 0)
		nbr = ft_strlen(var);
	i[0] = -1;
	aux[0] = ft_strjoin(var, "=");
	aux[1] = ft_strjoin(aux[0], value);
	free(aux[0]);
	while (!ft_strchr(var, '=') && env && env[++i[0]])
	{
		i[1] = nbr;
		if (i[1] < ft_strchr_index(env[i[0]], '='))
			i[1] = ft_strchr_index(env[i[0]], '=');
		if (!ft_strncmp(env[i[0]], var, i[1]))
		{
			aux[0] = env[i[0]];
			env[i[0]] = aux[1];
			free(aux[0]);
			return (env);
		}
	}
	env = ft_extend_matrix(env, aux[1]);
	free(aux[1]);
	return (env);
}
