/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 23:26:18 by fepinson          #+#    #+#             */
/*   Updated: 2019/04/19 11:25:23 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_split_line(char **line, char *s, char **rest)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(s);
	if ((i = (size_t)(ft_strchr(s, '\n') - s)))
	{
		j -= i;
		if (!(*line = ft_memalloc(i + 1)) 
				|| !(*rest = ft_memalloc(j + 1)))
			return (-1);
		j = i;
		while (--i)
			(*line)[i] = s[i];
		*line[i] = s[i];
		while (s[++j])
			(*rest)[i++] = s[j];
	}
	else
	{
		if (!(*line = ft_memalloc(1)))
			return (-1);
		if (j)
			if (!(*rest = ft_strdup(s + 1)))
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

	if (fd < 0 || fd > OPEN_MAX || !line )
		return (-1);
	if (rest[fd] && ft_strchr(rest[fd], '\n'))
		return (ft_split_line(line, rest[fd], &rest[fd]));
	else if (rest[fd])
		*line = rest[fd];
	else
		if (!(*line = ft_memalloc(1)))
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
	if (rt)
		rt = ft_split_line(line, *line, &rest[fd]);
	return (rt);
}
