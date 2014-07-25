/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 15:58:53 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/06 14:27:36 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_perror(const char *msg)
{
	extern const int			errno;
	extern const char * const	sys_errlist[];

	if (msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(sys_errlist[errno], 2);
}

void	error_msg(char *path, char *message)
{
	if (path)
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
	}
	if (message)
		ft_putendl_fd(message, 2);
	else
		ft_putendl_fd("...", 2);
}

void	error_msg_exit(char *path, char *message)
{
	error_msg(path, message);
	_exit(-1);
}
