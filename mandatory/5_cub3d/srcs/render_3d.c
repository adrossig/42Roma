/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:02:12 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 10:02:13 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_texture_color(t_tex *tex, int x, int y)
{
	int		offset;

	offset = (y * tex->data->size_line + x * (tex->data->bpp / 8));
	return (*(unsigned int *)(tex->data->addr + offset + 2) << 16 |
			*(unsigned int *)(tex->data->addr + offset + 1) << 8 |
			*(unsigned int *)(tex->data->addr + offset + 0) << 0);
}

static int	put_text(t_vars *vars, int y, int i, double *limit)
{
	t_ray	*ray;
	double	ymin;
	double	ymax;

	ray = NULL;
	ymin = limit[0];
	ymax = limit[1];
	ray = vars->ray[i];
	if (ray_facing(ray->ray_angle, ray_up) && ray->coord == HORZ)
		return (get_texture_color(vars->tex[north],
				(int)ray->collision->x % vars->tex[north]->width,
				(y - ymin) * (vars->tex[north]->height) / (ymax - ymin)));
	else if (ray_facing(ray->ray_angle, ray_down) && ray->coord == HORZ)
		return (get_texture_color(vars->tex[south],
				(int)ray->collision->x % vars->tex[south]->width,
				(y - ymin) * (vars->tex[south]->height) / (ymax - ymin)));
	else if (ray_facing(ray->ray_angle, ray_right) && ray->coord == VERT)
		return (get_texture_color(vars->tex[east],
				(int)ray->collision->y % vars->tex[east]->width,
				(y - ymin) * (vars->tex[east]->height) / (ymax - ymin)));
	else if (ray_facing(ray->ray_angle, ray_left) && ray->coord == VERT)
		return (get_texture_color(vars->tex[west],
				(int)ray->collision->y % vars->tex[west]->width,
				(y - ymin) * (vars->tex[west]->height) / (ymax - ymin)));
		return (0);
}

static void	put_colors(t_vars *vars, double wall_proj_height, int i)
{
	double	limit_y[2];
	int		x;
	int		y;

	limit_y[0] = (vars->map->height / 2) - (wall_proj_height / 2);
	limit_y[1] = (vars->map->height / 2) + (wall_proj_height / 2);
	x = i * WALL_WIDTH;
	while (x < (i + 1) * WALL_WIDTH)
	{
		y = -1;
		while (++y <= limit_y[0] && y < vars->map->height)
			my_mlx_pixel_put(vars->data, x, y, vars->map->color_ceiling);
		y--;
		while (++y <= limit_y[1] && y < vars->map->height)
			my_mlx_pixel_put(vars->data, x, y, put_text(vars, y, i, limit_y));
		y--;
		while (++y < vars->map->height)
			my_mlx_pixel_put(vars->data, x, y, vars->map->color_floor);
		x++;
	}
}

void		put_3dmap(t_vars *vars)
{
	double	correct_dist_plane;
	double	wall_proj_height;
	int		i;

	i = 0;
	while (i < vars->map->num_rays)
	{
		correct_dist_plane = vars->ray[i]->dist_wall *
					cos(vars->ray[i]->ray_angle - vars->player->rotation_angle);
		wall_proj_height = TILE_SIZE / correct_dist_plane *
							vars->player->dist_proj_plane;
		put_colors(vars, wall_proj_height, i);
		i++;
	}
}
