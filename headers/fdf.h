/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:41:09 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/16 19:39:54 by wdebotte         ###   ########.fr       */
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

int		ft_exit(const char *error, t_env *mlx, int status);
int		ft_openfile(char *filename);
int		ft_put_on_img(t_env *mlx);

void	ft_freemap(t_point **tab, int max_y);
void	ft_freestrtab(char **tab, char *line);
void	ft_checkmap(t_map *map, char *filename);
void	my_mlx_pixel_put(t_env *mlx, int x, int y, int color);
void	ft_keyhooks(t_env *mlx);

#endif
