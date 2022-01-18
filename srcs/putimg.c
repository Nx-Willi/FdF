/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:16:19 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/18 17:38:02 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static float	ft_iso_x(t_env *mlx, t_map *map, float x, float y)
{
	return ((x - y) * map->pt_space + mlx->win_width / 2
		- (((map->max_columns - 1) - (map->max_lines - 1)) / 2)
		* map->pt_space);
}

static float	ft_iso_y(t_env *mlx, t_map *map, float x, float y)
{
	return ((x + y) / 2 * map->pt_space - map->map[(int)y][(int)x].z
		+ mlx->win_height / 2 - ((((map->max_columns - 1)
		+ (map->max_lines - 1)) / 2) * map->pt_space) / 2);
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

int	ft_put_on_img(t_env *mlx)
{
	t_img	*img;

	img = &mlx->img;
	img->img = mlx_new_image(mlx->mlx, mlx->win_width + 10,
			mlx->win_height + 10);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx->map.pt_space = 20;
	ft_draw_map(mlx, &mlx->map);
	return (0);
}
