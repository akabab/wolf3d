/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 13:24:17 by ycribier          #+#    #+#             */
/*   Updated: 2014/02/27 20:51:33 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"

# define W_HEIGHT	600
# define W_WIDTH	800

# define MAP_HEIGHT	24
# define MAP_WIDTH	24

# define MTX		64
# define FOV		60

# define ALPHA		FOV / (double)W_WIDTH
# define GUI		(int)(0.4 * W_HEIGHT / MAP_HEIGHT)

# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307
# define KEY_SHIFT	65505
# define KEY_MORE	65451
# define KEY_LESS	65453

# define TOMI(X)	(int)((X) / MTX)

typedef struct		s_img
{
	void			*id;
	int				width;
	int				height;
	char			*addr;
	int				bpp;
	int				lsize;
	int				endian;
}					t_img;

typedef struct		s_keys
{
	t_bool			up;
	t_bool			down;
	t_bool			right;
	t_bool			left;
}					t_keys;

typedef struct		s_pt
{
	double			x;
	double			y;
}					t_pt;

typedef struct		s_player
{
	t_pt			pos;
	double			angle;
	int				speed;
}					t_player;

typedef struct		s_col
{
	double			angle;
	double			dst;
	char			type;
}					t_col;

typedef struct		s_dbg
{
	t_bool			infos;
	t_bool			mmap;
	t_img			*img;
}					t_dbg;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_img			*sky_img;
	t_keys			*keys;
	t_player		pl;
	t_dbg			dbg;
}					t_env;

/*
**		COLLISION
*/

t_pt	*get_vertical_collision(t_pt pos, double angle);
t_pt	*get_horizontal_collision(t_pt pos, double angle);

/*
**		DRAW
*/

void	clear_img(t_img *img);
void	my_pixel_put_to_image(t_img *img, int x, int y, int color);
void	draw_line(t_pt *pt1, t_pt *pt2, int color, t_img *img);
void	display_view(t_env *e);
t_img	*create_new_image(t_env *e, int width, int height);

/*
**		KEYS
*/

int		key_release(int keycode, t_env *e);
int		key_press(int keycode, t_env *e);
void	manage_keys(t_env *e);
t_keys	*init_keys(void);

/*
**		MOVEMENT
*/

void	move(int keycode, t_env *e);
void	rotate(int keycode, t_env *e);

/*
**		DEBUG
*/

# define KEY_DBG	96

# define RED		"31"
# define GREEN		"32"
# define YELLOW		"33"
# define BLUE		"34"
# define PINK		"35"
# define GRBL		"36"
# define GREY		"37"
# define NO			"0"
# define C(X)		"\033["X"m"

void	init_dbg(t_env *e);
void	manage_dbg(t_env *e);
void	display_minimap(t_env *e);

#endif /* !WOLF_H */
