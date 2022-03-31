/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:39:24 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/25 14:00:28 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		*fd;
	char	*str;
	size_t	i;
	size_t	j;

	fd = malloc(sizeof (int) * (argc - 1));
	if (!fd)
		return (1);
	i = 0;
	while (i < (size_t)argc - 1)
	{
		*(fd + i) = open(*(argv + i + 1), O_RDONLY);
		i++;
	}
	i = 0;
	j = 0;
	while (j < 5)
	{
		while (i < (size_t)argc - 1)
		{
			str = get_next_line(*(fd + i));
			printf("%s", str);
			free(str);
			str = get_next_line(10000000);
			if (!str)
				printf("HEIN!?");
			else
				printf("WHAT!?");
			i++;
		}
		i = 0;
		j++;
	}
	i = 0;
	while (i < (size_t)argc - 1)
	{
		close(*(fd + i));
		i++;
	}
	return (0);
}
