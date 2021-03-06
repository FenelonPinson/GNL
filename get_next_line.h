/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 23:27:38 by fepinson          #+#    #+#             */
/*   Updated: 2019/06/15 19:43:18 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>

# define BUFF_SIZE 32

typedef	struct	s_gnl
{
	char		*s;
	size_t		len;
	int			fd;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
