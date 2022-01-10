/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:08:39 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/10 21:14:32 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	ft_init_mlx(void)
{
	t_mlxenv	mlx;
	t_img		img;

	mlx.mlx = mlx_init();
	if (mlx.mlx != NULL)
	{
		mlx.win_width = 1920;
		mlx.win_height = 1080;
		mlx.window = mlx_new_window(mlx.mlx, mlx.win_width, mlx.win_height,
				"FdF");
		mlx.img = &img;
		img.img = mlx_new_image(mlx.mlx, mlx.win_width, mlx.win_height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		return (0);
	}
	return (ft_puterror("Can't init mlx env !"));
}

int	main(int args, char **argv)
{
	if (args != 2)
		return (ft_puterror("Command usage : ./fdf \"path_to_map.fdf\""));
	if (!is_ext_correct(argv[1], ".fdf"))
		return (ft_puterror("File extension doesn't match ! Must be \".fdf\""));
	if (ft_init_mlx() == INT_ERROR)
		return (INT_ERROR);
	ft_printf("%s\n", argv[1]);
	return (0);
}
