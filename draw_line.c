/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:59:44 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/14 21:18:36 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_win window, t_point p1, t_point p2)
{
	double	dx;
	double	dy;
	double	max;
	double	i;
	double	x_inc;
	double	y_inc;
	static	int		color[] = {0x000000ff,0x000000ff};

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (fabs(dx) > fabs(dy))
		max = fabs(dx);
	else
		max = fabs(dy);
	x_inc = dx / max;
	y_inc = dy / max;
	i = 0;
	while (i <= max)
	{
		mlx_pixel_put(window.mlx_ptr, window.win_ptr, round(p1.x), round(p1.y), color[(p1.z == 0)]);
		p1.x = x_inc + p1.x;
		p1.y = y_inc + p1.y;
		i++;
	}
}

