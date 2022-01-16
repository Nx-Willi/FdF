/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:54:14 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/16 18:52:11 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTURES_H
# define FDF_STRUCTURES_H

typedef struct s_point
{
	float	z;
	int		color;
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
