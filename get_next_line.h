/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:26:28 by leiamart          #+#    #+#             */
/*   Updated: 2024/06/25 22:14:36 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE
# endif

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_free(char *buffer, char *b);
char	*ft_line(char *buffer);
char	*ft_nextline(char *buffer);
char	*read_file(int fd, char *r);
char	*get_next_line(int fd);

#endif
