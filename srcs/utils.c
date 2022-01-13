/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:02:20 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/13 12:41:16 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	ft_puterror(const char	*error)
{
	ft_printf(STR_ERROR, error);
	return (INT_ERROR);
}

void	ft_freeinttab(int **tab, int max_y)
{
	int	y;

	y = 0;
	while (y < max_y)
		free(tab[y++]);
	free(tab);
}

void	ft_freestrtab(char **tab, char *line)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	if (line != NULL)
		free(line);
}

int	ft_openfile(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, "", 0) == -1)
	{
		ft_puterror("File doesn't exist !");
		return (-1);
	}
	return (fd);
}
