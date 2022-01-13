/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read_n_validate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:01:11 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/05 15:21:48 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (*line && line[i] == ' ')
		i++;
	if (line[i] != '\0')
	{
		free(line);
		return (FALSE);
	}
	free(line);
	return (TRUE);
}

int			end_of_file(int fd, char **line)
{
	while ((get_next_line(fd, line)))
	{
		if (!(is_empty_line(*line)))
			return (FALSE);
	}
	free(*line);
	return (TRUE);
}

static int	check_lack_info(t_map *map)
{
	if (!(validate_map(map)))
		return (ft_error(map, "ERROR: Invalid map"));
	else if (!map->n_column || !map->n_row)
		return (ft_error(map, "ERROR: No map was set in the cubfile"));
	else if (!map->width || !map->height ||
			map->width < map->n_column || map->height < map->n_row)
		return (ft_error(map, "ERROR: Invalid resolution"));
	else if (map->color_ceiling < 0 || map->color_floor < 0)
		return (ft_error(map, "ERROR: Invalid color"));
	else if (!map->path[north] || !*map->path[north] || !map->path[south] ||
			!*map->path[south] || !map->path[east] || !*map->path[east] ||
			!map->path[west] || !*map->path[west] || !map->path[sprite] ||
			!*map->path[sprite])
		return (ft_error(map, "ERROR: Invalid texture path"));
	else if (!map->sprite_posit)
		return (ft_error(map, "ERROR: nNo sprite was set on the map"));
	else if (!map->init_posit)
		return (ft_error(map, "ERROR: No player was set on the map"));
	return (1);
}

static int	fill_columns(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->n_row && map->map_grid[i])
	{
		j = 0;
		while (map->map_grid[i][j])
			j++;
		if (j < map->n_column)
			map->map_grid[i] = ft_strjoin_n_free(map->map_grid[i],
			ft_calloc_char(map->n_column - j, ' '));
		i++;
	}
	return (check_lack_info(map));
}

int			read_file(char *file, t_map *map)
{
	char	*line;
	int		fd;
	int		ismap;
	int		i;
	int		ret;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_error(map, "ERROR: The files does not exist"));
	ismap = FALSE;
	i = 0;
	while ((get_next_line(fd, &line)))
	{
		if (line[0] == ' ' || line[0] == '1')
		{
			if ((ret = get_map_info(map, line, &i, &ismap)) < 0)
				return (ft_error(map, "\e[31mERROR\e[39m"));
		}
		else if (is_identifier(line) && !ismap)
			get_identifier(map, line);
		else if (!(is_empty_line(line)) || (ismap && !end_of_file(fd, &line)))
			return (ft_error(map, "ERROR: Invalid line"));
	}
	free(line);
	close(fd);
	return (fill_columns(map));
}
