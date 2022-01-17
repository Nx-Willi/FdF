/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:58:03 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/17 17:46:49 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	ft_close_window()
{
	exit(EXIT_SUCCESS);
}

int	ft_hooks(int keycode, t_env *mlx)
{
	(void)mlx;
	if (keycode == ESC)
		return (ft_close_window());
	return (EXIT_SUCCESS);
}
