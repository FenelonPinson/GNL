/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:16:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/29 10:56:38 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	magic_loop(unsigned long int longword, const char *str,
		const unsigned long int *longword_ptr, const char *cp)
{
	unsigned long int			lomagic;
	unsigned long int			himagic;

	himagic = 0x8080808080808080L;
	lomagic = 0x101010101010101L;
	while (1)
	{
		longword = *longword_ptr++;
		if (((longword - lomagic) & ~longword & himagic))
		{
			cp = (const char *)(longword_ptr - 1);
			if (!cp[0] || !cp[1])
				return (!cp[0] ? cp - str : cp - str + 1);
			if (!cp[2] || !cp[3])
				return (!cp[2] ? cp - str + 2 : cp - str + 3);
			if (!cp[4] || !cp[5])
				return (!cp[4] ? cp - str + 4 : cp - str + 5);
			if (!cp[6] || !cp[7])
				return (!cp[6] ? cp - str + 6 : cp - str + 7);
		}
	}
}

size_t			ft_strlen(const char *str)
{
	const char				*char_ptr;
	const char				*cp;
	const unsigned long int	*longword_ptr;
	unsigned long int		longword;

	char_ptr = str;
	longword = 1;
	cp = 0;
	while (((unsigned long int)char_ptr & (sizeof(longword) - 1)))
	{
		if (*char_ptr == '\0')
			return (char_ptr - str);
		char_ptr++;
	}
	longword_ptr = (unsigned long int *)char_ptr;
	if (sizeof(longword) != 8)
		return (0);
	return (magic_loop(longword, str, longword_ptr, cp));
}
