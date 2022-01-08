/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:38:24 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/08 16:32:34 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "fdftest.h"
#include <stdlib.h>
#include <stdio.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lengh + x * (img->bits_pixels / 8));
	*(unsigned int*)dst = color;
}

//direction '0' = horizontal, '1' = vertical
void	ft_putline(t_img img, int x_start, int y_start, int pixels, 
					int direction)
{
	if (direction == 0)
	{
		while (x_start <= pixels)
		{
			my_mlx_pixel_put(&img, x_start, y_start, 0x0FFFFFF);
			x_start++;
		}
	}
	else if (direction == 1)
	{
		while (y_start <= pixels)
		{
			my_mlx_pixel_put(&img, x_start, y_start, 0x0FFFFFF);
			y_start++;
		}
	}
}

void	ft_putsquare(t_img img, int x_start, int y_start, int size)
{
	int	x = x_start;
	int	y = y_start;

	while (x <= x_start + size)
	{
		my_mlx_pixel_put(&img, x, y, 0x0FFFFFF);
		x++;
	}
	while (y <= y_start + size)
	{
		my_mlx_pixel_put(&img, x, y, 0x0FFFFFF);
		y++;
	}
	while (x >= x_start)
	{
		my_mlx_pixel_put(&img, x, y, 0x0FFFFFF);
		x--;
	}
	while (y >= y_start)
	{
		my_mlx_pixel_put(&img, x, y, 0x0FFFFFF);
		y--;
	}
}

int	main(int args, char **argv)
{
	t_env	mlx;
	t_img	img;

	if (args != 3)
	{
		mlx.size_x = 1920;
		mlx.size_y = 1080;
	}
	else
	{
		mlx.size_x = atoi(argv[1]);
		mlx.size_y = atoi(argv[2]);
	}
	img = mlx.img;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, mlx.size_x, mlx.size_y, "FdF Test");
	img.img = mlx_new_image(mlx.mlx, mlx.size_x, mlx.size_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_pixels, &img.line_lengh, 
								&img.endian);
	ft_putline(img, 0, 0, 100, 0);
	ft_putline(img, 0, 0, 100, 1);
	ft_putsquare(img, 1, 150, 100);
	mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
