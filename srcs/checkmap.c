/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:59:38 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/13 12:54:40 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	ft_readmap(t_map *map, int fd, int x, int y)
{
	char	*line;
	char	**temp_map;

	while (1)
	{
		line = get_next_line(fd);
		temp_map = ft_split(line, ' ');
		if (temp_map == NULL)
		{
			ft_freestrtab(temp_map, line);
			break ;
		}
		x = 0;
		while (temp_map[x] && temp_map[x][0] != '\n')
			x++;
		if (x > map->max_x)
			map->max_x = x;
		y++;
		ft_freestrtab(temp_map, line);
	}
	map->max_y = y;
	close(fd);
}

int	**ft_mallocmap(int max_x, int max_y)
{
	int	y;
	int	**map_tab;

	map_tab = (int **)malloc(sizeof(int *) * max_y + 1);
	if (map_tab == NULL)
		return (NULL);
	y = 0;
	while (y < max_y)
	{
		map_tab[y] = (int *)malloc(sizeof(int) * max_x);
		if (map_tab[y] == NULL)
		{
			ft_freeinttab(map_tab, max_y);
			return (NULL);
		}
		y++;
	}
	return (map_tab);
}

void	ft_fillmap(t_map *map, char *filename, int x, int y)
{
	int		fd;
	char	*line;
	char	**temp_map;

	fd = ft_openfile(filename);
	while (1)
	{
		line = get_next_line(fd);
		temp_map = ft_split(line, ' ');
		if (temp_map == NULL)
		{
			ft_freestrtab(temp_map, line);
			break ;
		}
		x = 0;
		while (x < map->max_x)
		{
			if (temp_map[x] != NULL)
				map->map[y][x] = ft_atoi(temp_map[x]);
			x++;
		}
		ft_freestrtab(temp_map, line);
		y++;
	}
	close(fd);
}

int	ft_checkmap(t_map *map, char *filename)
{
	int	fd;

	fd = ft_openfile(filename);
	if (fd < 0)
		return (INT_ERROR);
	map->max_x = 0;
	map->max_y = 0;
	ft_readmap(map, fd, 0, 0);
	map->map = ft_mallocmap(map->max_x, map->max_y);
	if (map->map == NULL)
		return (INT_ERROR);
	ft_fillmap(map, filename, 0, 0);
	return (0);
}
