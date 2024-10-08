/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:34:05 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/21 15:35:22 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	is_eol_in(char *str)
{
	size_t	i;

	i = 0;
	while (i++ < BUFFER_SIZE)
		if (*(str + i - 1) && *(str + i - 1) == '\n')
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem)
		ft_bzero(mem, count * size);
	return (mem);
}

void	*return_and_free(void *ret, void *fr)
{
	free(fr);
	return (ret);
}
