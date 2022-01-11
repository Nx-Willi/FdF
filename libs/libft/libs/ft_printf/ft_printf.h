/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:13:07 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/05 13:58:58 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define HEXA "0123456789abcdef"

int		ft_printf(const char *str, ...);
int		ft_printf_strlen(char *str);
int		ft_printf_putstr(char *str);
int		ft_printf_putnbr(int nb, int count);
int		ft_printf_putnbr_u(unsigned int nb, int count);
int		ft_printf_putnbr_hexa(int nb, int caps, int count);
int		ft_printf_putnbr_hexa_u(unsigned long long int nb, int count);

void	ft_printf_putchar(char c);

#endif
