/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:41:09 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/13 21:14:28 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define STR_ERROR "####################~\n# AN ERROR OCCURED !\n#\n# %s\n\
####################~\n"
# define INT_ERROR 404

# include "../libs/libft/headers/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "fdf_structures.h"
# include <unistd.h>
# include <fcntl.h>

int		ft_puterror(const char *error);
int		ft_openfile(char *filename);
int		ft_checkmap(t_map *map, char *filename);
int		ft_put_on_img(t_env *mlx);

void	ft_freeinttab(int **tab, int max_y);
void	ft_freestrtab(char **tab, char *line);

#endif
