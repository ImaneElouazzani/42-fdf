/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:57:12 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/16 17:05:27 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TRUE 1
# define FALSE 0
# define WIN_X 1000
# define WIN_Y 1000
# include "libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# define TRANS_X (WIN_X / 2 - (map->width * scale) / 2)
# define TRANS_Y (WIN_Y / 2 - (map->len * scale) / 2)

typedef	struct s_win	t_win;
typedef struct s_point	t_point;
typedef	struct s_map	t_map;
typedef struct s_incr	t_incr;

struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
};

struct	s_point
{
	double	x;
	double	y;
	double	z;
};

struct	s_incr
{
	int	i;
	int	j;
	int	k;
};

struct	s_map
{
	int		size;
	int		len;
	int		width;
	t_point	*tab;
	int		current_width;
	char	**split;
};

void	draw_line(t_win window, t_point p1, t_point p2);
void	store_point(t_win window, char *s, t_map *map);
void	draw_map(t_map *map, t_win window, int projection);
void	get_map_info(char *s, t_map *map);
int		change_projection(int keycode, void *my_msg);
void	ft_memdel2d(char **ptr);

#endif
