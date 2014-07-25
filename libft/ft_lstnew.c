/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 14:29:02 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/07 12:00:08 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if (!(lst = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(lst->content = ft_memalloc(content_size)))
	{
		free(lst);
		return (NULL);
	}
	ft_memcpy(lst->content, content, content_size);
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
