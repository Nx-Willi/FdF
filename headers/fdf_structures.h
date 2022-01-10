/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:54:14 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/10 20:12:30 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTURES_H
# define FDF_STRUCTURES_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlxenv
{
	void	*mlx;
	void	*window;
	int		win_width;
	int		win_height;
	t_img	*img;
}	t_mlxenv;

#endif
