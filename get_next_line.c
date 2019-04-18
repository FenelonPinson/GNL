/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 23:26:18 by fepinson          #+#    #+#             */
/*   Updated: 2019/04/18 16:58:30 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list *find_fd(t_list *list, int fd)
{
	if (list)
	{
		while (list->next)
		{
			if (((t_gnl *)list->content)->fd == fd)
				return (list);
			list = list->next;
		}
	}
	return (list);
}

void	del_gnl(void *s, size_t n)
{
	t_gnl *p;


	if ((p = (t_gnl*)s))
	{
		free(p->s);
		free(p);
	}
}

t_gnl	*new_gnl(char *str, size_t len, const int fd)
{
	t_gnl	*gnl;

	if ((gnl = (t_gnl *)malloc(sizeof(t_gnl))))
	{
		gnl->s = str;
		gnl->len = len;
		gnl->fd = (int)fd;
	}
	return (gnl);
}

int		handleft(char **line, t_list *left, int rt, size_t sz)
{
	char	*s1;
	char	*s2;
	size_t	len;

	if (rt)
	{
		s1 = *line;
		len = ((t_gnl *)left->content)->len;
		if (!(*line = (char *)ft_memalloc(sizeof(char) * (sz + 1)))
				|| !(s2 = (char *)malloc(sizeof(char) * len)))
			return (-1);
		ft_memcpy((void *)*line, (void *)s1, sz);
		ft_memcpy((void *)((t_gnl *)left->content)->s, (void *)s1 + sz + 1, len);
		s1 ? free(s1) : 0;
		s2 ? free(s2) : 0;
	}
	else
		*line = ft_memalloc(1);
	return (rt ? 1 : 0);
}

int		read_loop(char **line, t_list *left)
{
	char		buf[BUFF_SIZE];
	char		*s;
	size_t		sz;
	int			rt;

	if (!left)
		return (-1);
	*line = ((t_gnl *)left->content)->s;
	sz = ((t_gnl *)left->content)->len;
	while (!(((t_gnl *)left->content)->s = (char *)ft_memchr((void *)*line, 10, sz))
			&& (rt = read(((t_gnl *)left->content)->fd, buf, BUFF_SIZE)) > 0)
	{
		if (!(s = (char *)malloc(sizeof(char) * (sz + rt))))
			return (-1);
		ft_memcpy((void *)s, (void *)*line, (size_t)sz);
		ft_memcpy((void *)(s + sz), (void *)buf, (size_t)rt);
		*line ? free(*line) : 0;
		*line = s;
		sz += (size_t)rt;
	}
	((t_gnl *)left->content)->len = sz - 1 -
		(size_t)(((t_gnl *)left->content)->s - *line);
	sz = (size_t)(((t_gnl *)left->content)->s - *line);
	return (handleft(line, left, rt, sz));
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*left;
	t_list			*left_fd;
	t_list			*buf;
	int				rt;
	t_gnl			*pt;

	left_fd = NULL;
	if (fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	if (!left || !(left_fd = find_fd(left, fd)))
	{
		if (!(pt = new_gnl(NULL, 0, fd)))
			return (-1);
		if (!left)
			left = ft_lstnew((void const *)pt, sizeof(t_gnl));
		else
			ft_lstadd(&left, ft_lstnew((void const *)pt, sizeof(t_gnl)));
		free(pt);
	}
	if (!(rt = read_loop(line, !left_fd ? left : left_fd)))
	{
		buf = left;
		while (buf->next && buf->next != left_fd)
			buf = buf->next;
		buf->next ? buf->next = left_fd->next : 0;
		ft_lstdel(&left_fd, del_gnl);
	}
	return (rt);
}
