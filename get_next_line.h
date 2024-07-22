/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:26:28 by leiamart          #+#    #+#             */
/*   Updated: 2024/07/22 20:09:41 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

ssize_t	ft_strlengnl(char *str);
char	*ft_strchrgnl(char *str, int c);
char	*ft_strdupgnl(char *str);
char	*ft_substrgnl(char *str, unsigned int start, ssize_t len);
char	*ft_strjoingnl(char *s1, char *s2);
char	*ft_freegnl(char **str);
char	*ft_line(char *buffer, char **l);
char	*ft_readfile(int fd, char *r);
char	*get_next_line(int fd);

#endif
