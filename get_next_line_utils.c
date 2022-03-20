/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:34:05 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/19 16:10:39 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	is_eol_in(char *str)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
		if (*(str + i++) == '\n')
			return (i);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*((char *)s + i++) = 0;
}
