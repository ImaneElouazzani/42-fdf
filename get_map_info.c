/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <ielouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:58:41 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/16 17:01:48 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_out(int fd, int ret, char *s, t_map *map)
{
	if (fd < 0 || ret < 0 || map->size == 0 ||
			(map->current_width < map->width))
	{
		if (map->size == 0)
			ft_putendl("No data found.");
		else if (map->current_width < map->width)
			ft_putendl("Found wrong line length. Exiting.");
		else
			perror(s);
		exit(EXIT_FAILURE);
	}
}

void	ft_memdel2d(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	get_map_info(char *s, t_map *map)
{
	int		fd;
	char	*line;
	int		ret;

	map->size = 0;
	map->width = 0;
	fd = open(s, O_RDONLY);
	while (fd > 0 && (ret = get_next_line(fd, &line)) > 0)
	{
		map->split = ft_strsplit(line, ' ');
		map->current_width = -1;
		while (map->split[++(map->current_width)] != NULL)
			(map->size)++;
		if (map->width == 0)
			map->width = map->size;
		if (map->current_width < map->width)
			break ;
		if (map->current_width > map->width)
			map->size -= (map->current_width - map->width);
		(map->len)++;
		free(line);
		ft_memdel2d(map->split);
	}
	ft_out(fd, ret, s, map);
	close(fd);
}
