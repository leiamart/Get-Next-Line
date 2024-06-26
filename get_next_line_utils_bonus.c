/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:13:28 by leiamart          #+#    #+#             */
/*   Updated: 2024/06/26 16:51:14 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		*((char *)p +i) = 0;
		i++;
	}
	return (p);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{

	char	*r;
	int		size;
	int		i;
	int		c;

	i = 0;
	c = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	r = malloc(sizeof(char) * (size + 1));
	if (!r || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[c] != 0)
	{
		r[i] = s2[c];
		i++;
		c++;
	}
	r[size] = 0;
	return (r);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

char	*ft_free(char *buffer, char *b)
{
	char	*t;

	t = ft_strjoin(buffer, b);
	free(buffer);
	return (t);
}