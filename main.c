/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:55:17 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/08 22:45:33 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_win window;
	t_map map;

	if (ac == 2)
	{
		window.mlx_ptr = mlx_init();
		window.win_ptr = mlx_new_window(window.mlx_ptr,1000,1000,"hell");
		get_map_info(av[1], &map);
		store_point(window, av[1], &map);
		mlx_loop(window.mlx_ptr);
	}
	return (0);
}
