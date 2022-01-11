/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:59:38 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/11 15:40:16 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"
#include <fcntl.h>

int	ft_fillmap(t_map *map, int fd)
{
	char	*line;
	char	**temp_map;
	int		i;
	int		n;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp_map = ft_split(line, ' ');
		if (temp_map == NULL)
			break ;
		i = 0;
		n = 0;
		while (temp_map[i])
		{
			map->map[i][n] = ft_atoi(temp_map[i]);
			i++;
			n++;
		}
		map->max_x++;
	}
	return (1);
}

int	ft_checkmap(t_map *map, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || (read(fd, "", 0) == -1))
		return (INT_ERROR);
	map->max_x = 0;
	map->max_y = 0;
	ft_fillmap(map, fd);
	printf("=> %i\n", map->max_x);
	return (1);
}
