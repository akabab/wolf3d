/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 12:12:52 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/19 19:31:26 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "libft.h"
#include "wolf.h"

extern int	map[MAP_HEIGHT][MAP_WIDTH];

static t_bool	is_pt_valid(t_pt *pt)
{
	if (pt->x < 0
		|| pt->x >= MAP_WIDTH * MTX
		|| pt->y < 0
		|| pt->y >= MAP_HEIGHT * MTX)
		return (FALSE);
	return (TRUE);
}

static t_pt		*get_first_intersection(t_pt pos, double angle, char hv)
{
	t_pt	*pt;

	pt = malloc(sizeof(t_pt));
	if (hv == 'h')
	{
		if (angle > 0 && angle < 180)
			pt->y = TOMI(pos.y) * MTX - 1;
		else if (angle > 180 && angle < 360)
			pt->y = TOMI(pos.y) * MTX + MTX;
		else
			return (NULL);
		pt->x = pos.x + (pos.y - pt->y) / tanf(fdeg_to_rad(angle));
	}
	if (hv == 'v')
	{
		if (angle > 90 && angle < 270)
			pt->x = TOMI(pos.x) * MTX - 1;
		else if ((angle >= 0 && angle < 90) || (angle > 270 && angle < 360))
			pt->x = TOMI(pos.x) * MTX + MTX;
		else
			return (NULL);
		pt->y = pos.y + (pos.x - pt->x) * tanf(fdeg_to_rad(angle));
	}
	return (pt);
}

t_pt			*get_vertical_collision(t_pt pos, double angle)
{
	t_pt	*pt;
	t_pt	inc;

	pt = get_first_intersection(pos, angle, 'v');
	if (is_pt_valid(pt))
	{
		if (map[TOMI(pt->y)][TOMI(pt->x)] != 0)
			return (pt);
		else
		{
			if (angle > 90 && angle < 270)
				inc.x = - MTX;
			else if ((angle >= 0 && angle < 90) || (angle > 270 && angle < 360))
				inc.x = MTX;
			inc.y = (- inc.x) * tanf(fdeg_to_rad(angle));
			while (is_pt_valid(pt))
			{
				if (map[TOMI(pt->y)][TOMI(pt->x)] != 0)
					return (pt);
				pt->x += inc.x;
				pt->y += inc.y;
			}
		}
	}
	return (NULL);
}

t_pt			*get_horizontal_collision(t_pt pos, double angle)
{
	t_pt	*pt;
	t_pt	inc;

	pt = get_first_intersection(pos, angle, 'h');
	if (is_pt_valid(pt))
	{
		if (map[TOMI(pt->y)][TOMI(pt->x)] != 0)
			return (pt);
		else
		{
			if (angle > 0 && angle < 180)
				inc.y = - MTX;
			else if (angle > 180 && angle < 360)
				inc.y = MTX;
			inc.x = (- inc.y) / tanf(fdeg_to_rad(angle));
			while (is_pt_valid(pt))
			{
				if (map[TOMI(pt->y)][TOMI(pt->x)] != 0)
					return (pt);
				pt->x += inc.x;
				pt->y += inc.y;
			}
		}
	}
	return (NULL);
}
