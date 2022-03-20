/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:33:10 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/20 13:36:56 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static void	ft_cpy(char *dst, char buf[B_SIZE], size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(dst + i) = *(buf + i);
		i++;
	}
}

static char	*rec_gnl(int fd, char buf[B_SIZE], size_t len)
{
	ssize_t	n_read;
	size_t	n_buf;
	char	*str;
	char	r_buf[B_SIZE];

	ft_bzero(r_buf, B_SIZE * sizeof (char));
	n_read = read(fd, r_buf, B_SIZE);
	if ((!n_read && !len) || n_read == -1)
		return ((void *)0);
	n_buf = is_eol_in(r_buf);
	if (!n_buf && n_read)
	{
		str = rec_gnl(fd, buf, len + n_read);
		ft_cpy(str + len, r_buf, n_read);
		return (str);
	}
	len += n_buf;
	str = malloc(sizeof (char) * (len + 1));
	if (!str)
		return ((void *)0);
	*(str + len) = '\0';
	ft_cpy(str + len - n_buf, r_buf, n_buf);
	ft_cpy(buf, r_buf, B_SIZE);
	return (str);
}

static char	*terminate_and_clean(char *r_buf, char *buf, size_t st, size_t re)
{
	char	swap[B_SIZE];

	ft_bzero(swap, B_SIZE * sizeof (char));
	ft_cpy(swap, buf + st + re, B_SIZE - st - re);
	ft_cpy(buf, swap, B_SIZE);
	*(r_buf + re + 1) = '\0';
	*(r_buf + re) = '\n';
	return (r_buf);
}

static char	*process_buf(int fd, char *buf)
{
	size_t		st;
	size_t		re;
	char		*r_buf;
	char		*str;

	st = 0;
	re = 0;
	while (*(buf + st) != '\n')
		st++;
	if (st < B_SIZE - 1)
	{
		st++;
		while (st + re < B_SIZE && *(buf + st + re) && *(buf + st + re) != '\n')
			re++;
	}
	r_buf = malloc(sizeof (char) * (re + 2));
	if (!r_buf)
		return ((void *)0);
	ft_cpy(r_buf, buf + st, re);
	if (*(buf + st + re) == '\n')
		return (terminate_and_clean(r_buf, buf, st, re));
	str = rec_gnl(fd, buf, re);
	ft_cpy(str, r_buf, re);
	free(r_buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][B_SIZE];

	if (!**(buf + fd) || B_SIZE == 1)
		return (rec_gnl(fd, *(buf + fd), 0));
	return (process_buf(fd, *(buf +fd)));
}
