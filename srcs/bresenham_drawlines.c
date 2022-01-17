/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_drawlines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:59:10 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/17 17:43:58 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void    ft_putline(t_env *mlx, int x1, int y1, int x2, int y2, int color)
{
	int dx =  abs(x2 - x1);
	int    sx = x1 < x2 ? 1 : -1;
	int dy = -abs(y2 - y1);
	int sy = y1 < y2 ? 1 : -1;
	int err = dx + dy;
	int    e2; /* error value e_xy */

	while (1)
	{
			my_mlx_pixel_put(mlx, x1, y1, color);
			if (x1 == x2 && y1 == y2)
					break;
			e2 = 2 * err;
			if (e2 >= dy)
			{

					err += dy;
					x1 += sx;
			}
			if (e2 <= dx)
			{
					err += dx;
					y1 += sy;
			}
	}
}

void	ft_draw_line(t_env *mlx, t_point points)
{
		ft_putline(mlx, points.x1, points.y1, points.x2, points.y2, 0x00FFFFFF);
}
