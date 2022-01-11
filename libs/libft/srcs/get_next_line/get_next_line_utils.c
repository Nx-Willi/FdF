/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:32:55 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/11 10:57:38 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int		i;
	int		n;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (buffer == NULL)
		return (NULL);
	i = -1;
	n = -1;
	while (s1[++i] != '\0')
		buffer[i] = s1[i];
	while (s2[++n] != '\0')
		buffer[i + n] = s2[n];
	buffer[i + n] = '\0';
	free(s1);
	return (buffer);
}
