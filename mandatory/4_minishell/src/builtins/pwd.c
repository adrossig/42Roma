/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:24:01 by arossign          #+#    #+#             */
/*   Updated: 2022/03/13 17:25:07 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	minishell_pwd(void)
{
	char	*buff;

	buff = getcwd(NULL, 0);
	ft_putendl_fd(buff, 0);
	free(buff);
	return (0);
}
