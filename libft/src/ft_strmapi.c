/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:16:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/25 22:15:03 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char		*r;
	int			i;

	i = -1;
	if ((r = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) && f && s)
	{
		while (s[++i])
			r[i] = f((unsigned int)i, s[i]);
		r[i] = 0;
	}
	return (r);
}
