/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:01:42 by adrossig          #+#    #+#             */
/*   Updated: 2022/01/12 15:01:09 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "mlx_custom.h"

static int	allocate_map(t_vars *vars)
{
	vars->map = ft_calloc(1, sizeof(t_map));
	vars->map->init_posit = NULL;
	vars->map->color_ceiling = -1;
	vars->map->color_floor = -1;
	vars->map->path = ft_calloc(5, sizeof(char *));
	vars->map->path[north] = NULL;
	vars->map->path[south] = NULL;
	vars->map->path[east] = NULL;
	vars->map->path[west] = NULL;
	vars->map->path[sprite] = NULL;
	vars->map->init_posit = NULL;
	vars->map->sprite_posit = NULL;
	vars->map->map_grid = NULL;
	vars->map->n_sprites = 0;
	vars->map->width = 0;
	vars->map->height = 0;
	vars->map->n_row = 0;
	vars->map->n_column = 0;
	if (!(vars->mlx = mlx_init()))
		return (ft_error(vars->map, "ERROR: Mlx could not be initialized"));
	mlx_get_screen_size(vars->mlx, &vars->map->max_w, &vars->map->max_h);
	vars->win = NULL;
	return (1);
}

int			close_program(void)
{
	exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_vars	vars;

	check_args(argc, argv);
	allocate_map(&vars);
	if (!read_file(argv[1], vars.map) || !(create_n_check(&vars)))
		return (0);
	init_game(&vars, argc);
	mlx_hook(vars.win, 2, (1l << 0), move_player_press, &vars);
	mlx_hook(vars.win, 17, (1l << 17), clean_before_close, &vars);
	mlx_loop_hook(vars.mlx, update_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
