/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 13:13:54 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/19 19:53:40 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include </usr/X11R6/include/X11/X.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "libft.h"
#include "wolf.h"

int		loop_hook(t_env *e)
{
	clear_img(e->img);
	ft_memcpy(e->img->addr, e->sky_img->addr, 800 * 600 * 4);
	display_view(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	manage_keys(e);
	manage_dbg(e);
	return (0);
}

t_img	*create_new_image_from_xpm(t_env *e, char *name)
{
	t_img	*img;
	int		w;
	int		h;

	if (!(img = malloc(sizeof(t_img))))
	{
		ft_perror("[MLX]: New image alloc failed.");
		exit(EXIT_FAILURE);
	}
	if ((img->id = mlx_xpm_file_to_image(e->mlx, name, &w, &h)) == NULL)
	{
		ft_perror("[MLX]: New image creation failed.");
		exit(EXIT_FAILURE);
	}
	img->width = w;
	img->height = h;
	img->addr = mlx_get_data_addr(img->id, &img->bpp,
									&img->lsize, &img->endian);
	return (img);
}

t_img	*create_new_image(t_env *e, int width, int height)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
	{
		ft_perror("[MLX]: New image alloc failed.");
		exit(EXIT_FAILURE);
	}
	if ((img->id = mlx_new_image(e->mlx, width, height)) == NULL)
	{
		ft_perror("[MLX]: New image creation failed.");
		exit(EXIT_FAILURE);
	}
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->id, &img->bpp,
									&img->lsize, &img->endian);
	return (img);
}

t_env	*init_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (env == NULL)
	{
		ft_perror(NULL);
		exit(EXIT_FAILURE);
	}
	if ((env->mlx = mlx_init()) == NULL)
	{
		ft_perror("[MLX]: Connexion to server X failed.");
		exit(EXIT_FAILURE);
	}
	if (!(env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "~ Wolf3D ~")))
	{
		ft_perror("[MLX]: New window creation failed.");
		exit(EXIT_FAILURE);
	}
	return (env);
}

int		main(void)
{
	t_env		*e;

	e = init_env();
	e->img = create_new_image(e, W_WIDTH, W_HEIGHT);
	e->keys = init_keys();
	e->sky_img = create_new_image_from_xpm(e, "nsky.xpm");
	e->pl.pos.x = 5 * MTX + 32;
	e->pl.pos.y = 1 * MTX + 32;
	e->pl.angle = 271;
	e->pl.speed = 30;
	init_dbg(e);
	mlx_hook(e->win, KeyPress, KeyPressMask, &key_press, e);
	mlx_hook(e->win, KeyRelease, KeyReleaseMask, &key_release, e);
	mlx_loop_hook(e->mlx, &loop_hook, e);
	mlx_loop(e->mlx);
	return (EXIT_SUCCESS);
}
