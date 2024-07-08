/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:44:45 by leiamart          #+#    #+#             */
/*   Updated: 2024/07/08 20:23:44 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "limits.h"

char	*ft_free(char *buffer, char *b)
{
	char	*t;

	t = ft_strjoin(buffer, b);
	free(buffer);
	return (t);
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
	static char	*buffer[OPEN_MAX];
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	l = ft_line(buffer[fd]);
	buffer[fd] = ft_nextline(buffer[fd]);
	return (l);
}
