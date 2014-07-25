/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:11:54 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/10 00:33:03 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct		s_dlist_node
{
	struct s_dlist_node	*next;
	struct s_dlist_node	*prev;
	void				*value;
}					t_dlist_node;

typedef struct		s_dlist
{
	int				count;
	t_dlist_node	*first;
	t_dlist_node	*last;
}					t_dlist;

t_dlist		*list_create(void);
void		list_destroy(t_dlist *list);
void		list_clear(t_dlist *list);
void		list_clear_destroy(t_dlist *list);

# define list_count(A) ((A)->count)
# define list_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
# define list_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

void		list_push_back(t_dlist *list, void *value);
void		*list_pop_back(t_dlist *list);
void		list_push_front(t_dlist *list, void *value);
void		*list_pop_front(t_dlist *list);

void		*list_remove(t_dlist *list, t_dlist_node *node);

#endif /* !LIST_H */
