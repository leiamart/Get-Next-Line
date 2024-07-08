/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:25:19 by leiamart          #+#    #+#             */
/*   Updated: 2024/06/25 22:33:11 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*r;

	r = malloc(size * count);
	if (!r)
		return (NULL);
	ft_bzero(r, size * count);
	return (r);
}

size_t	ft_strlen(const char *s)
{
	int	i;

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
