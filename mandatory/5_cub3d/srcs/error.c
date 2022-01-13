/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:59:56 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 15:21:48 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_error(t_map *map, char *str)
{
	free_map(map);
	ft_putendl_fd(str, STDOUT_FILENO);
	return (close_program());
}

int			ft_path_error(t_vars *vars)
{
	ft_error(vars->map, "ERROR: Texture could not be loaded");
	mlx_destroy_window(vars->mlx, vars->win);
	return (close_program());
}

int			ft_arg_error(char *str)
{
	ft_putendl_fd(str, STDOUT_FILENO);
	return (close_program());
}
