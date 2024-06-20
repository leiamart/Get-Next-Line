/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:23:36 by leiamart          #+#    #+#             */
/*   Updated: 2024/06/20 21:55:35 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *aux_line)
{
	char	*buffer;
	int		read_bytes;
	char	*save;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(buffer, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(aux_line);
			aux_line = NULL;
			return (NULL);
		}
		save = aux_line;
		aux_line = ft_strjoin(save, buffer, read_bytes);
	}
	free(buffer);
	if (ft_strlen(aux_line) == 0)
		return (free (aux_line), NULL);
	return (aux_line);
}

char	*ft_getline(char *aux_line)
{
	char	*line;
	size_t	i;

	line = ft_calloc((ft_strlen(aux_line) + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (aux_line[i] != '\n' && aux_line[i])
	{
		line[i] = aux_line[i];
		i++;
	}
	if (aux_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_removeline(char *aux_line)
{
	char	*new_line;
	size_t	i;
	size_t	c;

	i = 0;
	while (aux_line[i] && aux_line[i] != '\n')
		i++;
	if (ft_strlen(aux_line) - i <= 0)
	{
		free(aux_line);
		aux_line = NULL;
		return (NULL);
	}
	new_line = ft_calloc((ft_strlen(aux_line) - i + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	i++;
	c = 0;
	while (aux_line[i] != '\0')
		new_line[c++] = aux_line[i++];
	free(aux_line);
	aux_line = NULL;
	return (new_line);
}

char *get_next_line(int fd)
{
	static char *buffer;

}







