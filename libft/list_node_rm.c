/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node_rm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 15:47:59 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/10 00:33:54 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

static void		list_remove_first(t_dlist *list, t_dlist_node *node)
{
	list->first = node->next;
	list->first->prev = NULL;
}

static void		list_remove_last(t_dlist *list, t_dlist_node *node)
{
	list->last = node->prev;
	list->last->next = NULL;
}

static void		list_remove_middle(t_dlist_node *node)
{
	t_dlist_node		*tmp_next;
	t_dlist_node		*tmp_prev;

	tmp_next = node->next;
	tmp_prev = node->prev;
	tmp_next->prev = tmp_prev;
	tmp_prev->next = tmp_next;
}

void			*list_remove(t_dlist *list, t_dlist_node *node)
{
	void	*del_node_value;

	del_node_value = NULL;
	if (list->first && list->last && node)
	{
		if (node == list->first && node == list->last)
		{
			list->first = NULL;
			list->last = NULL;
		}
		else if (node == list->first)
			list_remove_first(list, node);
		else if (node == list->last)
			list_remove_last(list, node);
		else
			list_remove_middle(node);
		list->count--;
		del_node_value = node->value;
		free(node);
	}
	return (del_node_value);
}
