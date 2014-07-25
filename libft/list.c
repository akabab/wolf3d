/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:19:31 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/10 00:33:20 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "list.h"

t_dlist		*list_create(void)
{
	t_dlist	*list;

	list = malloc(sizeof(t_dlist));
	if (!list)
	{
		ft_perror(NULL);
		return (NULL);
	}
	list->count = 0;
	list->first = NULL;
	list->last = NULL;
	return (list);
}

void		list_destroy(t_dlist *list)
{
	t_dlist_node		*cur;

	cur = list->first;
	while (cur != NULL)
	{
		if (cur->prev)
		{
			free(cur->prev);
		}
		cur = cur->next;
	}
	free(list->last);
	free(list);
}

void		list_clear(t_dlist *list)
{
	t_dlist_node		*cur;

	cur = list->first;
	while (cur != NULL)
	{
		free(cur->value);
		cur = cur->next;
	}
}

void		list_clear_destroy(t_dlist *list)
{
	list_clear(list);
	list_destroy(list);
}
