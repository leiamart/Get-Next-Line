/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:26:28 by leiamart          #+#    #+#             */
/*   Updated: 2024/06/12 21:44:56 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE
# endif

#include "unistd.h"

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *aux_line, char *buffer, int read_bytes);
char	*ft_strchr(const char *s, int c);


char *get_next_line(int fd);

#endif
