/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 12:44:42 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/29 20:00:00 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "wolf.h"

int		key_release(int keycode, t_env *e)
{
	if (keycode == KEY_RIGHT)
		e->keys->right = FALSE;
	if (keycode == KEY_LEFT)
		e->keys->left = FALSE;
	if (keycode == KEY_UP)
		e->keys->up = FALSE;
	if (keycode == KEY_DOWN)
		e->keys->down = FALSE;
	if (keycode == KEY_SHIFT)
		e->pl.speed = 30;
	if (keycode == KEY_DBG)
	{
		e->dbg.infos = !e->dbg.infos;
		e->dbg.mmap = !e->dbg.mmap;
	}
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int		key_press(int keycode, t_env *e)
{
	if (keycode == KEY_RIGHT)
		e->keys->right = TRUE;
	if (keycode == KEY_LEFT)
		e->keys->left = TRUE;
	if (keycode == KEY_UP)
		e->keys->up = TRUE;
	if (keycode == KEY_DOWN)
		e->keys->down = TRUE;
	if (keycode == KEY_SHIFT)
		e->pl.speed = 80;
	if (keycode == KEY_MORE)
		e->pl.speed++;
	if (keycode == KEY_LESS)
		e->pl.speed--;
	return (0);
}

void	manage_keys(t_env *e)
{
	if (e->keys->up == TRUE)
		move(KEY_UP, e);
	if (e->keys->down == TRUE)
		move(KEY_DOWN, e);
	if (e->keys->right == TRUE)
		rotate(KEY_RIGHT, e);
	if (e->keys->left == TRUE)
		rotate(KEY_LEFT, e);
}

t_keys	*init_keys(void)
{
	t_keys		*keys;

	keys = malloc(sizeof(keys));
	if (keys == NULL)
		exit(EXIT_FAILURE);
	keys->up = FALSE;
	keys->down = FALSE;
	keys->right = FALSE;
	keys->left = FALSE;
	return (keys);
}
