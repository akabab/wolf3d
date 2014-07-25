/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:23:56 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/08 16:25:30 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "list.h"

void	list_push_back(t_dlist *list, void *value)
{
	t_dlist_node		*node;

	node = malloc(sizeof(t_dlist_node));
	if (!node)
	{
		ft_perror(NULL);
		return ;
	}
	node->value = value;
	if (list->last == NULL)
	{
		list->first = node;
		list->last = node;
	}
	else
	{
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}
	list->count++;
}

void	*list_pop_back(t_dlist *list)
{
	t_dlist_node		*node;

	node = list->last;
	if (node)
		return (list_remove(list, node));
	return (NULL);
}

void	list_push_front(t_dlist *list, void *value)
{
	t_dlist_node		*node;

	node = malloc(sizeof(t_dlist_node));
	if (!node)
	{
		ft_perror(NULL);
		return ;
	}
	node->value = value;
	if (list->first == NULL)
	{
		list->first = node;
		list->last = node;
	}
	else
	{
		node->next = list->first;
		list->first->prev = node;
		list->first = node;
	}
	list->count++;
}

void	*list_pop_front(t_dlist *list)
{
	t_dlist_node		*node;

	node = list->first;
	if (node)
		return (list_remove(list, node));
	return (NULL);
}
