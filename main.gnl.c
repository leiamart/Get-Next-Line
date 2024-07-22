/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:12:55 by leiamart          #+#    #+#             */
/*   Updated: 2024/07/22 18:19:53 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "string.h"
#include "stdio.h"

int	main(int argc, char *argv[])
{
	int	c;
	int	fd;
	int	fdb;
	int	fdb2;
	char	*l;
	int	size;

	c = 20;
	fd = open("prueba.txt", O_RDONLY);
	fdb = open("prueba_bonus.txt", O_RDONLY);
	fdb2 = open("prueba2_bonus.txt", O_RDONLY);
	if (argc > 1 && !strcmp("bonus", argv[1]))
	{
		int	file;
		file = 1;
		
		while (--c >= 0)
        {
		if (file == 1)
		{
			l = get_next_line(fdb);
			file++;
		}
		else
		{
			l = get_next_line(fdb2);
			file--;
		}
		if (l)
		{
			size = ft_strlengnl(l);
			write(1, l, size);
		}
		free(l);
	}
	}
	else
	{
		while (--c > 0)
		{
			l = get_next_line(fd);
			if (l)
			{
				size = ft_strlengnl(l);
				write(1, l, size);
			}
			free(l);
			l = NULL;
		}
	}
	close(fd);
	close(fdb);
	close(fdb2);
	return (0);
}

