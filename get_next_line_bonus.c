/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:44:45 by leiamart          #+#    #+#             */
/*   Updated: 2024/07/22 17:23:51 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_freegnl(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_line(char *buffer, char **l)
{
	char	*r;
	int		i;

	r = NULL;
	i = ft_strlengnl(buffer);
	if (!buffer || !l)
		return (NULL);
	if (ft_strchrgnl(buffer, '\n'))
	{
		r = ft_strdupgnl(ft_strchrgnl(buffer, '\n') + 1);
		(*l) = ft_substrgnl(buffer, 0, i - ft_strlengnl(r));
	}
	else
	{
		(*l) = ft_substrgnl(buffer, 0, i);
	}
	ft_freegnl(&buffer);
	return (r);
}

char	*ft_readfile(int fd, char *r)
{
	ssize_t		readbytes;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readbytes = 1;
	buffer[0] = '\0';
	while (!ft_strchrgnl(buffer, '\n') && readbytes != 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
		{
			ft_freegnl(&buffer);
			ft_freegnl(&r);
			return (NULL);
		}
		buffer[readbytes] = '\0';
		if (readbytes > 0)
			r = ft_strjoingnl(r, buffer);
	}
	ft_freegnl(&buffer);
	return (r);
}

char	*get_next_line(int fd)
{
	static char		*buffer[1024];
	char			*l;

	l = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd] || !ft_strchrgnl(buffer[fd], '\n'))
		buffer[fd] = ft_readfile(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = ft_line(buffer[fd], &l);
	return (l);
}
