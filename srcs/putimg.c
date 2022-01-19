/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:16:19 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/19 16:58:48 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static float	ft_iso_x(t_env *mlx, t_map *map, float x, float y)
{
	return ((x - y) * map->scale + mlx->win_width / 2
		- (((map->max_columns - 1) - (map->max_lines - 1)) / 2)
		* map->scale);
}

static float	ft_iso_y(t_env *mlx, t_map *map, float x, float y)
{
	return ((x + y) / 2 * map->scale - map->map[(int)y][(int)x].z
		+ mlx->win_height / 2 - ((((map->max_columns - 1)
		+ (map->max_lines - 1)) / 2) * map->scale) / 2);
}

static void	ft_draw_map(t_env *mlx, t_map *map)
{
	float		x;
	float		y;

	y = -1;
	while (++y < map->max_lines)
	{
		x = -1;
		while (++x < map->max_columns)
		{
			map->map[(int)y][(int)x].x1 = ft_iso_x(mlx, map, x, y);
			map->map[(int)y][(int)x].y1 = ft_iso_y(mlx, map, x, y);
			if (x < map->max_columns - 1)
			{
				map->map[(int)y][(int)x].x2 = ft_iso_x(mlx, map, x + 1, y);
				map->map[(int)y][(int)x].y2 = ft_iso_y(mlx, map, x + 1, y);
				ft_putline(mlx, map->map, (int)x, (int)y);
			}
			if (y < map->max_lines - 1)
			{
				map->map[(int)y][(int)x].x2 = ft_iso_x(mlx, map, x, y + 1);
				map->map[(int)y][(int)x].y2 = ft_iso_y(mlx, map, x, y + 1);
				ft_putline(mlx, map->map, (int)x, (int)y);
			}
		}
	}
}

static void	ft_get_points_space(t_env *mlx)
{
	int		max_columns;
	int		max_lines;
	t_map	*map;

	map = &mlx->map;
	max_columns = map->max_columns;
	max_lines = map->max_lines;
	if (max_columns >= max_lines)
	{
		while (ft_iso_x(mlx, map, max_columns - 1, 0) > mlx->win_width - 200)
			map->scale -= 0.1;
	}
	else
	{
		while (ft_iso_x(mlx, map, max_columns - 1, 0) > mlx->win_width - 200)
			map->scale -= 0.1;
	}
}

int	ft_put_on_img(t_env *mlx)
{
	t_img	*img;

	img = &mlx->img;
	img->img = mlx_new_image(mlx->mlx, mlx->win_width + 10,
			mlx->win_height + 10);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	ft_get_points_space(mlx);
	ft_draw_map(mlx, &mlx->map);
	return (0);
}
