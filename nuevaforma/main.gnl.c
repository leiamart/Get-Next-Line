/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:12:55 by leiamart          #+#    #+#             */
/*   Updated: 2024/07/10 21:14:57 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int main(int argc,char *argv[])
{
    int count = 10;
    int fd = open("prueba.txt", O_RDONLY);
    int fdb = open("prueba_bonus.txt", O_RDONLY);
    int fdb2 = open("prueba2_bonus.txt", O_RDONLY);
    char *line;
    int size;
    
    if (argc > 1 && !strcmp("bonus", argv[1]))
    {
        int file = 1;

        while (--count >= 0)
        {
            if (file == 1)
            {
                line = get_next_line(fdb);
                file++;
            }
            else
            {
                line = get_next_line(fdb2);
                file--;
            }
            size = ft_strlen(line);
            write(1, line, size);
            free(line);
        }
    }
    else
    {
        while (--count >= 0)
        {
            line = get_next_line(fd);
            size = ft_strlen(line);
            write(1, line, size);
            free(line);
        }
    }
    close(fd);
    close(fdb);
    close(fdb2);
    return (0);
}
