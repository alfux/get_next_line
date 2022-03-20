/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:46:46 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/20 18:13:04 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	main(int argc, char **argv)
{
	char	*str;
	int		*fd;
	size_t	i;
	size_t	j;

	i = 0;
	if (argc == 1)
	{
		while (i++ < 10)
		{
			str = get_next_line(0);
			printf("%s", str);
			free(str);
		}
		return (0);
	}
	fd = malloc((argc - 1) * sizeof (int));
	while (i++ < (size_t)argc - 1)
		*(fd + i - 1) = open(*(argv + i), O_RDONLY);
	i = 0;
	j = 0;
	while (i++ < 10)
	{
		while (j++ < (size_t)argc - 1)
		{
			str = get_next_line(*(fd + j - 1));
			printf("%s", str);
			free(str);
		}
		j = 0;
	}
	while (j < (size_t)argc - 1)
		close(*(fd + j++));
	free(fd);
	return (0);
}
