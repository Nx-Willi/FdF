/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:16:19 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/16 20:35:56 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	ft_draw_points(t_env *mlx, t_img *img, t_map *map)
{
	float		x;
	float		y;
	float		x_i;
	float		y_i;
	int			pt_space;

	(void)img;
	pt_space = map->pt_space;
	y = 0;
	while (y < map->max_lines)
	{
		x = 0;
		while (x < map->max_columns)
		{
			x_i = ((x - y) * pt_space) + (mlx->win_width / 2);
			y_i = (((x + y) / 2) * pt_space)
				- map->map[(int)y][(int)x].z + (mlx->win_height / 3);
			if (map->map[(int)y][(int)x].z == 0.0)
				my_mlx_pixel_put(mlx, x_i, y_i, 0x00FF0000);
			else
				my_mlx_pixel_put(mlx, x_i, y_i, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}

int	ft_put_on_img(t_env *mlx)
{
	t_img	*img;

	img = &mlx->img;
	img->img = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx->map.pt_space = 10;
	ft_draw_points(mlx, &mlx->img, &mlx->map);
	return (0);
}
