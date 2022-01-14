/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:16:19 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/14 18:16:06 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

/*
isoX = cartX - cartY;
isoY = (cartX + cartY) / 2;
*/
void	ft_draw_points(t_env *mlx, t_img *img, t_map *map)
{
	int	x;
	int	x_i;
	int	y;
	int	y_i;
	int	pt_space;

	pt_space = map->pt_space;
	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			x_i = (x - y) + (mlx->win_width / 2);
			y_i = (x + y) / 2 + (mlx->win_height / 2);
			if (map->map[y][x] == 0)
				my_mlx_pixel_put(img, x_i, y_i, 0x00FF0000);
			else
				my_mlx_pixel_put(img, x_i, y_i, 0x00FFFFFF);
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
	mlx->map.pt_space = 5;
	ft_draw_points(mlx, &mlx->img, &mlx->map);
	return (0);
}
