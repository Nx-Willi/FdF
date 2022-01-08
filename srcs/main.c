/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:08:39 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/08 22:39:51 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	main(int args, char **argv)
{
	if (args != 2)
	{
		ft_puterror("Command usage : ./fdf \"path_to_map.fdf\"");
		return (INT_ERROR);
	}
	if (!is_ext_correct(argv[1], ".fdf"))
	{
		ft_puterror("File extension doesn't match ! Must be \".fdf\"");
		return (INT_ERROR);
	}
	ft_printf("%s\n", argv[1]);
	return (0);
}
