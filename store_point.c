/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:59:08 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/08 22:44:33 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	store_point(t_win window, char *s, t_map *map)
{
	int fd;
	char *line;
	int		i;
	int		j;
	char	*tmp;
	int h;
	int k;

	fd = open(s, O_RDONLY);
	j = 0;
	h = 0;
	map->tab = (t_point *)malloc(map->size * sizeof(t_point));
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		tmp = line;
		while (*line != '\0')
		{
			if (ft_isdigit(*line) == TRUE)
			{
				(map->tab[h]).z = ft_atoi(line);
				(map->tab[h]).x = i * 100;
				(map->tab[h]).y = j * 100;
				h++;
				i++;
			}
			line++;
		}
		j++;
		free(tmp);
	}
	i = 0;
	k = 1;
	while (i < map->size)
	{
	//	printf("x = %f y = %f z =%f %s\n", (tab[i]).x, (tab[i]).y, (tab[i]).z, "o");
		if( (i + 1) < map->width * k )
			draw_line(window, map->tab[i], map->tab[i + 1]);
		else
			k++;
		if ( (i + map->width) < map->size)
			draw_line(window, map->tab[i], map->tab[i + (map->width)]);
		i++;
	}
	close(fd);
}
