/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:23:36 by leiamart          #+#    #+#             */
/*   Updated: 2024/06/25 22:41:34 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *buffer)
{
	char	*l;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	l = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		l[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		l[i++] = '\n';
	return (l);
}

char	*ft_nextline(char *buffer)
{
	char	*n;
	int		c;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	n = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	c = 0;
	while (buffer[i])
		n[c++] = buffer[i++];
	free(buffer);
	return (n);
}

char	*read_file(int fd, char *r)
{
	int		readbyte;
	char	*buffer;

	if (!r)
		r = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readbyte = 1;
	while (readbyte > 0)
	{
		readbyte = read(fd, buffer, BUFFER_SIZE);
		if (readbyte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readbyte] = 0;
		r = ft_free(r, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (r);
}

char	*get_next_line(int fd)
{
	char		*l;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	l = ft_line(buffer);
	buffer = ft_nextline(buffer);
	return (l);
}
