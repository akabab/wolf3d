/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:13:11 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/09 14:58:01 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

int					checkline(char *buffer)
{
	int				j;

	j = 0;
	while (buffer[j] != '\0')
	{
		if (buffer[j] == '\n')
		{
			buffer[j] = '\0';
			return (0);
		}
		j++;
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	char			*str;
	int				bytes;
	static char		*buffer = "";

	bytes = GNL_BUFF_SIZE;
	if (bytes == 0)
		return (0);
	while (checkline(buffer) && bytes == GNL_BUFF_SIZE)
	{
		str = (char *)ft_memalloc(sizeof(char) * (GNL_BUFF_SIZE + 1));
		ft_strclr(str);
		bytes = read(fd, str, GNL_BUFF_SIZE);
		if (bytes == -1)
			return (-1);
		buffer = ft_strjoin(buffer, str);
		free(str);
	}
	str = (char *)ft_memalloc(sizeof(char) * (ft_strlen(buffer) + 1));
	ft_memcpy(str, buffer, ft_strlen(buffer));
	buffer = buffer + ft_strlen(str) + 1;
	*line = ft_strdup(str);
	free(str);
	if (bytes > 1 || (bytes == 0 && ft_strlen(*line) > 0))
		return (1);
	return (bytes);
}
