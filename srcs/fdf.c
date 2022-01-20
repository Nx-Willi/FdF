/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:08:39 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/20 17:31:28 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void	ft_init_mlx(t_env *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		ft_exit("An error occured while creating mlx environment !\
 Please try again !", mlx, NULL, EXIT_FAILURE);
	mlx->win_width = 1920;
	mlx->win_height = 1080;
	mlx->window = mlx_new_window(mlx->mlx, mlx->win_width, mlx->win_height,
			"FdF - wdebotte");
	if (mlx->window == NULL)
		ft_exit("An error occured while creating the window !",
			mlx, NULL, EXIT_FAILURE);
}

int	main(int args, char **argv)
{
	t_env	mlx;

	if (args < 2 || args > 3)
		return (ft_exit("Command usage : ./fdf \"path_to_map.fdf\"\
 (optionnal)\"scale\"", NULL, NULL, EXIT_FAILURE));
	if (!is_ext_correct(argv[1], ".fdf"))
		return (ft_exit("File extension doesn't match ! Must be \".fdf\"",
				NULL, NULL, EXIT_FAILURE));
	ft_checkmap(&mlx.map, argv[1]);
	ft_init_mlx(&mlx);
	if (argv[2] != NULL)
		mlx.map.scale = (float)ft_atoi(argv[2]);
	else
		mlx.map.scale = 100.0;
	ft_put_on_img(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img.img, 0, 0);
	mlx_key_hook(mlx.window, ft_hooks, &mlx);
	mlx_hook(mlx.window, DESTROYNOTIFY, NOTIFYMASK, ft_close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (ft_exit(NULL, &mlx, &mlx.map, EXIT_SUCCESS));
}
