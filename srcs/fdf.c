/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:08:39 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/14 15:46:38 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	ft_printfmap(t_map *map, int max_x, int max_y)
{
	int		x;
	int		y;

	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
			ft_printf("%i ", map->map[y][x++]);
		ft_printf("\n");
		y++;
	}
	ft_freeinttab(map->map, max_y);
}

void	ft_init_mlx(t_env *mlx, char *width, char *height)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		ft_exit("An error occured while creating mlx environment !\
 Please try again !", mlx, EXIT_FAILURE);
	if (width != NULL && height != NULL)
	{
		mlx->win_width = ft_atoi(width);
		mlx->win_height = ft_atoi(height);
	}
	else
	{
		mlx->win_width = 1920;
		mlx->win_height = 1080;
	}
	mlx->window = mlx_new_window(mlx->mlx, mlx->win_width, mlx->win_height,
			"FdF - wdebotte");
	if (mlx->window == NULL)
		ft_exit("An error occured while creating the window !",
			mlx, EXIT_FAILURE);
}

int	main(int args, char **argv)
{
	t_env	mlx;

	if (args < 2 || args > 4)
		return (ft_exit("Command usage : ./fdf \"path_to_map.fdf\"\
 \"window_width\"(optionnal) \"window_height\"(optionnal)", NULL,
				EXIT_FAILURE));
	if (!is_ext_correct(argv[1], ".fdf"))
		return (ft_exit("File extension doesn't match ! Must be \".fdf\"",
				NULL, EXIT_FAILURE));
	ft_checkmap(&mlx.map, argv[1]);
	if (args == 4)
		ft_init_mlx(&mlx, argv[2], argv[3]);
	else
		ft_init_mlx(&mlx, NULL, NULL);
	ft_put_on_img(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx);
	ft_printfmap(&mlx.map, mlx.map.max_x, mlx.map.max_y);
	return (ft_exit(NULL, &mlx, EXIT_SUCCESS));
}
