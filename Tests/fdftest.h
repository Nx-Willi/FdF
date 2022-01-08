/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdftest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:23:51 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/08 15:31:38 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDFTEST_H
# define FDFTEST_H

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bits_pixels;
	int		line_lengh;
	int		endian;
}	t_img;

typedef struct s_env
{
	void			*mlx;
	void			*window;
	int				size_x;
	int				size_y;
	struct s_img	img;
}	t_env;

#endif
