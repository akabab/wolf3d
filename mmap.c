/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 17:54:11 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/19 20:11:55 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf.h"

extern int	map[MAP_HEIGHT][MAP_WIDTH];

static void		display_grid(t_img *img)
{
	int				x;
	int				y;
	int				color;

	color = 0x111111;
	y = 0;
	while (y < MAP_HEIGHT * GUI)
	{
		x = 0;
		while (x < MAP_WIDTH * GUI)
		{
			if (fmod(x, GUI) == 0 || fmod(y, GUI) == 0)
				my_pixel_put_to_image(img, x - 1, y - 1, color);
			x++;
		}
		y++;
	}
}

static double	fdtr(double angle)
{
	return (fdeg_to_rad(angle));
}

static void		display_player_position(t_env *e)
{
	t_pt			ptpl;
	t_pt			pt1;
	t_pt			pt2;
	t_pt			pt_amid;

	ptpl.x = e->pl.pos.x / MTX * GUI;
	ptpl.y = e->pl.pos.y / MTX * GUI;
	pt1.x = (e->pl.pos.x / MTX + cosf(fdtr(e->pl.angle - 90)) * 0.5) * GUI;
	pt1.y = (e->pl.pos.y / MTX - sinf(fdtr(e->pl.angle - 90)) * 0.5) * GUI;
	pt2.x = (e->pl.pos.x / MTX + cosf(fdtr(e->pl.angle + 90)) * 0.5) * GUI;
	pt2.y = (e->pl.pos.y / MTX - sinf(fdtr(e->pl.angle + 90)) * 0.5) * GUI;
	draw_line(&pt1, &pt2, 0xEEEEEE, e->dbg.img);
	pt1.x = (e->pl.pos.x / MTX + cosf(fdtr(e->pl.angle - 30)) * 50) * GUI;
	pt1.y = (e->pl.pos.y / MTX - sinf(fdtr(e->pl.angle - 30)) * 50) * GUI;
	draw_line(&ptpl, &pt1, 0xEEEEEE, e->dbg.img);
	pt2.x = (e->pl.pos.x / MTX + cosf(fdtr(e->pl.angle + 30)) * 50) * GUI;
	pt2.y = (e->pl.pos.y / MTX - sinf(fdtr(e->pl.angle + 30)) * 50) * GUI;
	draw_line(&ptpl, &pt2, 0xEEEEEE, e->dbg.img);
	draw_line(&pt1, &pt2, 0xEEEEEE, e->dbg.img);
	pt_amid.x = (e->pl.pos.x / MTX + cosf(fdtr(e->pl.angle)) * 50) * GUI;
	pt_amid.y = (e->pl.pos.y / MTX - sinf(fdtr(e->pl.angle)) * 50) * GUI;
	draw_line(&ptpl, &pt_amid, 0xFFFFFF, e->dbg.img);
}

void			display_minimap(t_env *e)
{
	int				x;
	int				y;
	int				color;

	y = 0;
	while (y < MAP_HEIGHT * GUI)
	{
		x = 0;
		while (x < MAP_WIDTH * GUI)
		{
			color = 0x666666 * map[y / GUI][x / GUI];
			my_pixel_put_to_image(e->dbg.img, x, y, color);
			x++;
		}
		y++;
	}
	display_grid(e->dbg.img);
	display_player_position(e);
}
