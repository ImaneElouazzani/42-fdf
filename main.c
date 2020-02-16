/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <ielouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:55:17 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/16 17:27:29 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
