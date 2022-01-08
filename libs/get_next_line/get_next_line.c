/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:32:16 by wdebotte          #+#    #+#             */
/*   Updated: 2021/12/21 09:02:37 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_rest(char *buffer)
{
	char	*rest;
	int		i;
	int		n;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (rest == NULL)
		return (NULL);
	n = 0;
	while (buffer[i] != '\0')
		rest[n++] = buffer[++i];
	free(buffer);
	rest[n] = '\0';
	if (rest[0] == '\0')
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*get_read(int fd, char *buffer)
{
	int		bytes;
	char	*read_line;

	read_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_line == NULL)
		return (NULL);
	read_line[0] = 0;
	bytes = 1;
	while (bytes && !ft_strchr(read_line, '\n'))
	{
		bytes = read(fd, read_line, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(read_line);
			return (NULL);
		}
		read_line[bytes] = '\0';
		buffer = ft_strjoin(buffer, read_line);
	}
	free(read_line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, "", 0) == -1)
		return (NULL);
	buffer = get_read(fd, buffer);
	line = get_line(buffer);
	buffer = get_rest(buffer);
	return (line);
}
