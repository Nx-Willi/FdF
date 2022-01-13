/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:08:39 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/13 21:21:03 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	ft_printfmap(t_map *map, int max_x, int max_y)
{
	int	x;
	int	y;

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

int	ft_init_mlx(t_env *mlx, char *width, char *height)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (ft_puterror("Impossible to create mlx environment !\
 Please try again !"));
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
		return (ft_puterror("An error occured while creating the window !"));
	return (0);
}

int	main(int args, char **argv)
{
	t_env	mlx;

	if (args < 2 || args > 4)
		return (ft_puterror("Command usage : ./fdf \"path_to_map.fdf\"\
 \"window_width\"(optionnal) \"window_height\"(optionnal)"));
	if (!is_ext_correct(argv[1], ".fdf"))
		return (ft_puterror("File extension doesn't match ! Must be \".fdf\""));
	if (ft_checkmap(&mlx.map, argv[1]) == INT_ERROR)
		return (ft_puterror("An error occured while checking the map."));
	if (args == 4)
	{
		if (ft_init_mlx(&mlx, argv[2], argv[3]) == INT_ERROR)
			return (INT_ERROR);
	}
	else
		if (ft_init_mlx(&mlx, NULL, NULL) == INT_ERROR)
			return (INT_ERROR);
	ft_put_on_img(&mlx);
	ft_printfmap(&mlx.map, mlx.map.max_x, mlx.map.max_y);
	return (0);
}
