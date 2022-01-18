/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:54:14 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/18 17:51:03 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTURES_H
# define FDF_STRUCTURES_H

typedef struct s_bres
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
	int	x1_tmp;
	int	y1_tmp;
}	t_bres;

typedef struct s_point
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		z;
	char	*color;
	t_bres	bres;
}	t_point;

typedef struct s_map
{
	int		max_columns;
	int		max_lines;
	int		pt_space;
	t_point	**map;
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
