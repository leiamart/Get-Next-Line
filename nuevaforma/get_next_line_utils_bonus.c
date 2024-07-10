/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:13:28 by leiamart          #+#    #+#             */
/*   Updated: 2024/07/08 20:19:30 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchrgnl(char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == (char) c)
			return ((char *) &str[i]);
	if (str[i] == (char) c)
		return ((char *) &str[i]);
	return (NULL);
}

ssize_t	ft_strlengnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substrgnl(char *str, unsigned int start, ssize_t len)
{
	char	*substr;
	ssize_t	i;

	i = -1;
	if (start >= ft_strlengnl(str))
		return (NULL);
	if (len + start > ft_strlengnl(str))
		len = ft_strlengnl(str) - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (++i < len)
		substr[i] = str[i + start];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdupgnl(char *str)
{
	char	*p;
	int		i;

	i = -1;
	p = (char *)malloc(sizeof(char) * ft_strlengnl(str) + 1);
	if (!p)
		return (NULL);
	while (str[++i])
		p[i] = str[i];
	p[i] = '\0';
	return (p);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	char	*s3;
	ssize_t	i;
	ssize_t	c;

	i = -1;
	c = -1;
	if (!s1)
		s1 = ft_strdupgnl("");
	if (!s1)
		return (NULL);
	s3 = malloc(sizeof(char) * ft_strlengnl(s1) + ft_strlengnl(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++c])
		s3[i++] = s2[c];
	s3[i] = '\0';
	return (ft_free(&s1), s3);
}
