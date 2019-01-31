/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <pinsonfen@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 10:09:24 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/25 18:46:49 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	i = 0;
	if ((s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
	{
		while (s && s1[i])
		{
			s[i] = s1[i];
			++i;
		}
		s[i] = 0;
	}
	return (s);
}
