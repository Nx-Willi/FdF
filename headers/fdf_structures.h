/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:54:14 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/13 15:32:15 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTURES_H
# define FDF_STRUCTURES_H

typedef struct s_map
{
	int	max_x;
	int	max_y;
	int	pt_space;
	int	**map;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_env
{
	void	*mlx;
	void	*window;
	int		win_width;
	int		win_height;
	t_img	img;
	t_map	map;
}	t_env;

#endif
