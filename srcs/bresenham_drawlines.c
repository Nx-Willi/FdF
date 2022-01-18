/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_drawlines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:59:10 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/18 14:22:24 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void	ft_define_bres_var(t_bres *bres, t_point **points, int x, int y)
{
	bres->dx = abs(points[y][x].x2 - points[y][x].x1);
	if (points[y][x].x1 < points[y][x].x2)
		bres->sx = 1;
	else
		bres->sx = -1;
	bres->dy = -abs(points[y][x].y2 - points[y][x].y1);
	if (points[y][x].y1 < points[y][x].y2)
		bres->sy = 1;
	else
		bres->sy = -1;
	bres->err = bres->dx + bres->dy;
	bres->x1_tmp = points[y][x].x1;
	bres->y1_tmp = points[y][x].y1;
}

void	ft_putline(t_env *mlx, t_point **points, int x, int y)
{
	t_bres	*bres;

	bres = &points[y][x].bres;
	ft_define_bres_var(bres, points, x, y);
	while (1)
	{
		my_mlx_pixel_put(mlx, bres->x1_tmp, bres->y1_tmp, 0x00FFFFFF);
		if (bres->x1_tmp == points[y][x].x2 &&
			bres->y1_tmp == points[y][x].y2)
			break ;
		bres->e2 = 2 * bres->err;
		if (bres->e2 >= bres->dy)
		{
			bres->err += bres->dy;
			bres->x1_tmp += bres->sx;
		}
		if (bres->e2 <= bres->dx)
		{
			bres->err += bres->dx;
			bres->y1_tmp += bres->sy;
		}
	}
}
