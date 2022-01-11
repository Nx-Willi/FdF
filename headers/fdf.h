/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:41:09 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/11 11:30:37 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define STR_ERROR "##########~\n# AN ERROR OCCURED !\n#\n# %s\n##########~\n"
# define INT_ERROR 404

# include "../libs/libft/headers/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "fdf_structures.h"
# include <stdio.h>
# include <stdlib.h>

int	ft_puterror(const char *error)
{
	ft_printf(STR_ERROR, error);
	return (INT_ERROR);
}

#endif
