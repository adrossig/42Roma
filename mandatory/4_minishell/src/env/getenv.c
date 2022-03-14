/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:51:29 by arossign          #+#    #+#             */
/*   Updated: 2022/03/14 09:59:51 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*minishell_getenv(char *var, char **env, int nbr)
{
	int	i;
	int	tmp;

	i = 0;
	if (nbr < 0)
		nbr = ft_strlen(var);
	while (!ft_strchr(var, '=') && env && env[i])
	{
		tmp = nbr;
		if (tmp < ft_strchr_index(env[i], '='))
			tmp = ft_strchr_index(env[i], '=');
		if (!ft_strncmp(env[i], var, tmp))
			return (ft_substr(env[i], tmp + 1, ft_strlen(env[i])));
		i++;
	}
	return (NULL);
}
