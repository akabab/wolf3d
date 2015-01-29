/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 06:45:37 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/29 19:42:57 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "wolf.h"

static void	manage_unique_collision(t_pt *pt1, t_pt *pt2, t_col *col, t_env *e)
{
	if (!pt1 && !pt2)
		error_msg("!(pt1 & pt2)");
	else if (!pt1)
	{
		col->dst = fabs((e->pl.pos.x - pt2->x) / cosf(fdeg_to_rad(col->angle)));
		col->type = 2;
	}
	else if (!pt2)
	{
		col->dst = fabs((e->pl.pos.x - pt1->x) / cosf(fdeg_to_rad(col->angle)));
		col->type = 1;
	}
}

static void	get_collision_infos(t_pt *pt1, t_pt *pt2, t_col *col, t_env *e)
{
	double			dst[3];
	static char		p = 0;

	manage_unique_collision(pt1, pt2, col, e);
	if (pt1 && pt2)
	{
		dst[1] = fabs((e->pl.pos.x - pt1->x) / cosf(fdeg_to_rad(col->angle)));
		dst[2] = fabs((e->pl.pos.x - pt2->x) / cosf(fdeg_to_rad(col->angle)));
		if (TOMI(pt1->x) == TOMI(pt2->x) && TOMI(pt1->y) == TOMI(pt2->y) && p)
		{
			col->dst = dst[(int)p];
			col->type = p;
		}
		else
		{
			col->dst = fmin(dst[1], dst[2]);
			if (dst[1] < dst[2])
				col->type = 1;
			else
				col->type = 2;
		}
	}
	p = col->type;
}

#include <stdio.h>

static void	draw_column(t_img *img, int i, double dst, int color)
{
	int		j;
	int		j0;
	int		clr;
	double	height;

	height = MTX / dst * 693;
	j = 0;
	j0 = (W_HEIGHT - height) / 2;
	if (j0 < 0)
		j0 = 0;
	while (j < height && j < W_HEIGHT)
	{
		if (j  < 0.02 * height || j > 0.98 * height)
		{
			clr = 0xFFFFFF;
		}
		clr = color;
		my_pixel_put_to_image(img, i, j0 + j, clr);
		j++;
	}
}

static int	get_color(double angle, char type)
{
	if (angle > 180 && angle < 360 && type == 1)
		return (0x2C3E50);
	if (angle > 0 && angle < 180 && type == 1)
		return (0x3498DB);
	if (angle > 90 && angle < 270 && type == 2)
		return (0xE74C3C);
	if (((angle > 270 && angle < 360)|| (angle >= 0 && angle < 90))
			&& type == 2)
		return (0xECF0F1);
	return (0xFF0000);
}

void		display_view(t_env *e)
{
	double	angle;
	double	dst;
	t_pt	*pt1;
	t_pt	*pt2;
	t_col	col;
	int		x;
	int		color;

	x = 0;
	angle = e->pl.angle + 30;
	while (x < W_WIDTH)
	{
		pt1 = get_horizontal_collision(e->pl.pos, fdeg(angle));
		pt2 = get_vertical_collision(e->pl.pos, fdeg(angle));
		col.angle = angle;
		get_collision_infos(pt1, pt2, &col, e);
		color = get_color(fdeg(angle), col.type);
		dst = col.dst * cosf(fdeg_to_rad(e->pl.angle - angle));
		draw_column(e->img, x, dst, color);
		angle -= ALPHA;
		x++;
	}
}
