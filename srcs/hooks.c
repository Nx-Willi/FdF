/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:58:03 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/20 16:45:44 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	ft_close_window(t_env *mlx)
{
	return (ft_exit(NULL, mlx, EXIT_SUCCESS));
}

int	ft_hooks(int keycode, t_env *mlx)
{
	if (keycode == ESC)
		return (ft_close_window(mlx));
	return (EXIT_SUCCESS);
}
