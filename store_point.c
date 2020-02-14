/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:59:08 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/14 16:39:34 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pp(t_point *tab, int len)
{
	int		i;

	i = 0;

	while (i < len)
	{
		printf("x %.f\ty %.f\tz %f\n", (tab[i]).x, (tab[i]).y, (tab[i]).z);
		i++;
	}
}

void	projection(t_point *p, int	type)
{
	double x;

	if (type == 1 )
	{
		x = p->x;
		p->x = (x - p->y) * cos(0.523599);
		p->y = (x + p->y) * sin(0.523599) - p->z;
		p->x += 500;
	}
}

void	draw_map(t_map *map, t_win window)
{
	int	i;
	int	k;
	t_point	p1;
	t_point	p2;

	i = 0;
	k = 1;
	while (i < map->size)
	{
		p1 = map->tab[i];
		projection(&p1, 1);
		if((i + 1) < map->width * k )
		{
			p2 = map->tab[i + 1];
			projection(&p2, 1);
			draw_line(window, p1, p2);
		}
		else
			k++;
		if ( (i + map->width) < map->size)
		{
			p2 = map->tab[i + (map->width)];
			projection(&p2, 1);
			draw_line(window, p1, p2);
		}
		i++;
	}
}

void	store_point(t_win window, char *s, t_map *map)
{

	char	*line;
	char	**tab;
	int		i;
	int		j;
	int		k;
	int		fd;
	double	scale;

	k = 0;
	j = 0;
	fd = open(s, O_RDONLY);
	map->tab = (t_point *)malloc(map->size *sizeof(t_point));
	scale = 500 / map->width;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		tab = ft_strsplit(line, ' ');
		while(tab[i] != NULL)
		{
			map->tab[k].x = i * scale + (WIN_X / 2 - (map->width * scale) / 2);
			map->tab[k].y = j * scale + (WIN_Y / 2 - (map->len * scale) / 2);
			map->tab[k].z = ft_atoi(tab[i]) * scale;
			i++;
			k++;
		}
		j++;
	}
	close(fd);
}
