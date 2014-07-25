/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 01:45:37 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/19 19:35:58 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "wolf.h"

void			clear_img(t_img *img)
{
	int		i;
	int		j;

	j = 0;
	while (j < img->height)
	{
		i = 0;
		while (i < img->width)
		{
			my_pixel_put_to_image(img, i, j, 0x000000);
			i++;
		}
		j++;
	}
}

static void		dbg_infos(t_env *e)
{
	char	*dbg_angle;
	char	*dbg_pos;
	char	*dbg_speed;
	char	*tmp1;
	char	*tmp2;

	dbg_angle = ft_strjoin("angle: ", ft_itoa((int)e->pl.angle));
	tmp1 = ft_strjoin3("[", ft_itoa((int)e->pl.pos.y), "]");
	tmp2 = ft_strjoin3("[", ft_itoa((int)e->pl.pos.x), "]");
	dbg_pos = ft_strjoin3("pos[y][x]: ", tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	free(dbg_pos);
	dbg_speed = ft_strjoin("speed: x", ft_itoa(e->pl.speed));
	mlx_string_put(e->mlx, e->win, 5, 15, 0xAAAAAA, dbg_angle);
	mlx_string_put(e->mlx, e->win, 70, 15, 0xAAAAAA, dbg_pos);
	mlx_string_put(e->mlx, e->win, 220, 15, 0xAAAAAA, dbg_speed);
}

void			manage_dbg(t_env *e)
{
	if (e->dbg.infos == TRUE)
		dbg_infos(e);
	if (e->dbg.mmap == TRUE)
	{
		display_minimap(e);
		mlx_put_image_to_window(e->mlx, e->win, e->dbg.img->id, 10, 20);
	}
}

void			init_dbg(t_env *e)
{
	int		mm_width;
	int		mm_height;

	mm_width = MAP_WIDTH * GUI;
	mm_height = MAP_HEIGHT * GUI;
	e->dbg.infos = FALSE;
	e->dbg.mmap = FALSE;
	e->dbg.img = create_new_image(e, mm_width, mm_height);
}
