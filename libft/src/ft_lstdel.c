/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:16:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/02/01 11:35:44 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *buf;

	if (!alst)
		return ;
	while (*alst)
	{
		if (del)
			del((*alst)->content, (*alst)->content_size);
		else
			free((*alst)->content);
		buf = (*alst)->next;
		free(*alst);
		*alst = buf;
	}
}
