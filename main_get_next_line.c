/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:08:23 by leiamart          #+#    #+#             */
/*   Updated: 2024/06/12 21:45:56 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*l;
	int		i;
	int		fd;
	if (argc != 2)
		return (0);


	fd = open(argv[1], O_RDONLY);
	i = 1;
	while (i < 10)

	
	{
		l = get_next_line(fd);
		printf("line [%d]: %s", i, l);
		free(l);
		i++;
	}
	close(fd);
	return (0);
}
