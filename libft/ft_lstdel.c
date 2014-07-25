/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 16:14:19 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/09 23:26:08 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*begin_lst;

	if (alst)
	{
		begin_lst = *alst;
		while ((*alst) != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			tmp = *alst;
			free(*alst);
			*alst = tmp->next;
		}
		begin_lst = NULL;
	}
}
