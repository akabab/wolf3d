/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 08:15:43 by ycribier          #+#    #+#             */
/*   Updated: 2014/01/19 17:42:53 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	_cos[360];
double	_sin[360];

void	cos_sin_tabs(void)
{
	int		angle;

	angle = 0;
	while (angle < 360)
	{
		_cos[angle] = cosf(M_PI * angle / 180);
		_sin[angle] = sinf(M_PI * angle  / 180);
		angle++;
	}
}
