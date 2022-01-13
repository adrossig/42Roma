/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:00:38 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 15:21:48 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_is_cub(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 4;
	if (ft_memcmp(&str[i], ".cub", 4))
		return (0);
	return (1);
}

int			check_args(int argc, char **argv)
{
	if (argc == 1)
		return (ft_arg_error("ERROR: No argument"));
	else if (argc > 3)
		return (ft_arg_error("ERROR: Too many arguments"));
	else if (!(ft_is_cub(argv[1])))
		return (ft_arg_error("ERROR: First argument is not .cub"));
	else if (argc == 3 && ft_memcmp(argv[2], "--save", 6))
		return (ft_arg_error("ERROR: Second argument is invalid. Try --save"));
	return (0);
}

int			is_identifier(char *line)
{
	if (ft_c_is_in(line[0], "RCFS") ||
		(line[0] == 'N' && line[1] == 'O') ||
		(line[0] == 'W' && line[1] == 'E') ||
		(line[0] == 'E' && line[1] == 'A') ||
		(line[0] == 'S' && line[1] == '0'))
		return (TRUE);
	return (FALSE);
}
