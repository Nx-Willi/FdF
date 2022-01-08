/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:41:09 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/08 22:22:14 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define STR_ERROR "##########~\n# AN ERROR OCCURED !\n#\n# %s\n##########~\n"
# define INT_ERROR 404

# include "../libs/libft/headers/libft.h"
# include "../libs/ft_printf/ft_printf.h"

void	ft_puterror(const char *error)
{
	ft_printf(STR_ERROR, error);
}

#endif
