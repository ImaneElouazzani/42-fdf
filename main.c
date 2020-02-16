/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:55:17 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/16 17:20:19 by ielouazz         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_win window;
	t_map map;

	if (ac == 2)
	{
		get_map_info(av[1], &map);
		window.mlx_ptr = mlx_init();
		window.win_ptr = mlx_new_window(window.mlx_ptr, WIN_X, WIN_Y, "hell");
		window.map = &map;
		store_point(window, av[1], &map);
		draw_map(&map, window, 0);
		mlx_key_hook(window.win_ptr, rcv_key_events, &window);
		mlx_hook(window.win_ptr, 17, 0, ft_exit, map.tab);
		mlx_loop(window.mlx_ptr);
	}
	return (0);
}
