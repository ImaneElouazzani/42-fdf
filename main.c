/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:55:17 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/14 16:15:50 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		rcv_key_events(int keycode, void *params)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_exit(void *params)
{
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_win window;
	t_map map;

	if (ac == 2)
	{
		window.mlx_ptr = mlx_init();
		window.win_ptr = mlx_new_window(window.mlx_ptr, WIN_X, WIN_Y, "hell");
		get_map_info(av[1], &map);
		store_point(window, av[1], &map);
		draw_map(&map, window);
		mlx_key_hook(window.win_ptr, rcv_key_events, NULL);
		mlx_hook(window.win_ptr, 17, 0, ft_exit, NULL);
		mlx_loop(window.mlx_ptr);
	}
	return (0);
}
