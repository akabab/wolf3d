/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:24:38 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/19 19:33:27 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "wolf.h"

void			my_pixel_put_to_image(t_img *img, int x, int y, int color)
{
	int				i;
	int				mask;
	char			tmp_clr;
	int				offset;

	i = 0;
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		while (i < (img->bpp / 8))
		{
			if (img->endian == 1)
				offset = img->bpp - 8 * (i + 1);
			else
				offset = 8 * i;
			mask = 0xFF << offset;
			tmp_clr = (color & mask) >> offset;
			img->addr[y * (img->lsize) + x * (img->bpp / 8) + i] = tmp_clr;
			i++;
		}
	}
}

static void		draw_line_1(t_pt *pt1, t_pt *pt2, int color, t_img *img)
{
	int	x;
	int	y;

	x = pt1->x;
	while (x <= pt2->x)
	{
		y = pt1->y + ((pt2->y - pt1->y) * (x - pt1->x)) / (pt2->x - pt1->x);
		my_pixel_put_to_image(img, x, y, color);
		x++;
	}
}

static void		draw_line_2(t_pt *pt1, t_pt *pt2, int color, t_img *img)
{
	int	x;
	int	y;

	y = pt1->y;
	if (pt1->x == pt2->x && pt1->y == pt2->y)
	{
		my_pixel_put_to_image(img, pt1->x, pt1->y, color);
		return ;
	}
	while (y <= pt2->y)
	{
		x = pt1->x + ((pt2->x - pt1->x) * (y - pt1->y)) / (pt2->y - pt1->y);
		my_pixel_put_to_image(img, x, y, color);
		y++;
	}
}

void			draw_line(t_pt *pt1, t_pt *pt2, int color, t_img *img)
{
	if ((ft_abs(pt1->x - pt2->x) > ft_abs(pt1->y - pt2->y)))
	{
		if (pt1->x < pt2->x)
			draw_line_1(pt1, pt2, color, img);
		else
			draw_line_1(pt2, pt1, color, img);
	}
	else
	{
		if (pt1->y < pt2->y)
			draw_line_2(pt1, pt2, color, img);
		else
			draw_line_2(pt2, pt1, color, img);
	}
}
