/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 12:43:09 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/19 19:35:42 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf.h"

extern int	map[MAP_HEIGHT][MAP_WIDTH];

void	rotate(int keycode, t_env *e)
{
	if (keycode == KEY_LEFT)
		e->pl.angle = fdeg(e->pl.angle + ALPHA * e->pl.speed);
	if (keycode == KEY_RIGHT)
		e->pl.angle = fdeg(e->pl.angle - ALPHA * e->pl.speed);
}

void	move(int keycode, t_env *e)
{
	double	move_x;
	double	move_y;

	if (keycode == KEY_UP)
	{
		move_x = cosf(fdeg_to_rad(e->pl.angle)) * 0.1 * e->pl.speed;
		move_y = - sinf(fdeg_to_rad(e->pl.angle)) * 0.1 * e->pl.speed;
	}
	if (keycode == KEY_DOWN)
	{
		move_x = - cosf(fdeg_to_rad(e->pl.angle)) * 0.1 * e->pl.speed;
		move_y = sinf(fdeg_to_rad(e->pl.angle)) * 0.1 * e->pl.speed;
	}
	if (map[TOMI(e->pl.pos.y)][TOMI(e->pl.pos.x + move_x)] == 0)
		e->pl.pos.x += move_x;
	if (map[TOMI(e->pl.pos.y + move_y)][TOMI(e->pl.pos.x)] == 0)
		e->pl.pos.y += move_y;
}
