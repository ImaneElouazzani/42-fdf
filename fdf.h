/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:57:12 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/08 22:46:10 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#define TRUE 1
#define FALSE 0
#include "libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <math.h>

typedef	struct	s_win t_win;
typedef struct	s_point t_point;
typedef	struct	s_map t_map;

struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
};

struct	s_point
{
	double	x;
	double	y;
	double	z;
};

struct	s_map
{
	int 	size;
	int		width;
	t_point	*tab;
};

void	draw_line(t_win window, t_point p1, t_point p2);
void	store_point(t_win window, char *s, t_map *map);
void	get_map_info(char *s, t_map *map);

#endif

