/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 23:26:18 by fepinson          #+#    #+#             */
/*   Updated: 2019/06/17 12:46:03 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_split_line(char **line, char *s, char **rest)
{
	ssize_t	i;
	ssize_t	j;

	i = ft_strlen(s);
	if ((j = (size_t)(ft_strchr(s, '\n') - s)))
	{
		i -= j;
		if (!(*line = (char *)ft_memalloc(j + 1)) 
			|| !(*rest = (char *)ft_memalloc(i + 1)))
			return (-1);
		i = j;
		while (--j != -1)
			(*line)[j] = s[j];
		while (s[++i])
			(*rest)[++j] = s[i];
	}
	else
	{
		if (!(*line = (char *)ft_memalloc(1)))
			return (-1);
		if (i && !(*rest = ft_strdup(s + 1)))
			return (-1);
	}
	free(s);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*rest[OPEN_MAX];
	char			*buf;
	char			*s;
	int				rt;

	if (fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	if (rest[fd] && ft_strchr(rest[fd], '\n'))
		return (ft_split_line(line, rest[fd], &rest[fd]));
	else if ((*line = rest[fd]))
		rest[fd] = NULL;
	else if (!(*line = ft_memalloc(1)))
		return (-1);
	if (!(buf = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	while (!ft_strchr(*line, '\n') && (rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = 0;
		s = *line;
		*line = ft_strjoin(*line, buf);
		free(s);
	}
	free(buf);
	rt = rt > 0 ? ft_split_line(line, *line, &rest[fd]) : rt;
	return (!rt && **line ? 1 : rt);
}
