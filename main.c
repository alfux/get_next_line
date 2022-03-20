/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:46:46 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/20 16:21:54 by afuchs           ###   ########.fr       */
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
	int		fd;
	int		fd2;

	(void)argc;
	(void)argv;
	fd = open("get_next_line.h", O_RDONLY);
	fd2 = open("test", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd2);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd2);
	printf("%s", str);
	free(str);
	close(fd);
	close(fd2);
	return (0);
}
