/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:02:04 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 10:02:05 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_wall(t_map *map, int x, int y, char identf)
{
	int	grid_x;
	int	grid_y;

	if (is_end_window(map, x, y))
		return (TRUE);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	if (grid_x >= map->n_column || grid_y >= map->n_row)
		return (TRUE);
	if (map->map_grid[grid_y][grid_x] == identf)
		return (TRUE);
	return (FALSE);
}

int		is_end_window(t_map *map, double x, double y)
{
	if (x < 0 || x >= map->n_column * TILE_SIZE ||
		y < 0 || y >= map->n_row * TILE_SIZE)
		return (TRUE);
	return (FALSE);
}
