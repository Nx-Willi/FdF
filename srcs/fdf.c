/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:08:39 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/11 14:41:15 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	main(int args, char **argv)
{
	t_env	mlx;

	if (args != 2)
		return (ft_puterror("Command usage : ./fdf \"path_to_map.fdf\""));
	if (!is_ext_correct(argv[1], ".fdf"))
		return (ft_puterror("File extension doesn't match ! Must be \".fdf\""));
	if (ft_checkmap(&mlx.map, argv[1]) == INT_ERROR)
		return (ft_puterror("An error occured while reading the file !"));
	return (0);
}
