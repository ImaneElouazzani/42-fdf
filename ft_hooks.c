/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <ielouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:06:58 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/16 17:29:48 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		rcv_key_events(int keycode, t_win *window)
{
	static	int	p = 1;

	if (keycode == 53)
	{
		free(window->map->tab);
		exit(0);
	}
	if (keycode == 8)
	{
		mlx_clear_window(window->mlx_ptr, window->win_ptr);
		draw_map(window->map, *window, p);
		if (p == 0)
			p = 1;
		else
			p = 0;
	}
	return (0);
}

int		ft_exit(t_point *tab)
{
	free(tab);
	exit(0);
	return (0);
}
