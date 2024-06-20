/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:25:19 by leiamart          #+#    #+#             */
/*   Updated: 2024/06/19 22:16:48 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		*((char *)p + i) = 0;
		i++;
	}
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (((char *)s)[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *aux_line, char *buffer, int read_bytes)
{
	char	*str;
	int		i;
	int		j;

	if (!aux_line)
		aux_line = ft_calloc(1, 1);
	str = malloc((ft_strlen(aux_line) + read_bytes + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (aux_line[j])
		str[i++] = aux_line[j++];
	j = 0;
	while (j < read_bytes)
		str[i++] = buffer[j++];
	str[i] = '\0';
	free (aux_line);
	return (str);
}


char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!(*s))
			return (NULL);
		s++;
	}
	return ((char *)s);
}

int	ft_free()
{

}
