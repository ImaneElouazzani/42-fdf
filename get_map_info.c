/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:58:41 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/13 20:18:57 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_info(char *s,t_map *map)
{
	int		fd;
	char	*line;
	int		i;
	char	**tab;

	map->size = 0;
	map->width = 0;
	fd = open(s, O_RDONLY);
	while(get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		i = 0;
		while (tab[i] != NULL)
		{
			map->size++;
			i++;
		}
		if (map->width == 0)
			map->width = map->size;
		map->len++;
	}
	printf("%d \n",map->width);
	close(fd);
}
