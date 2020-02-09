/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:58:41 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/08 22:42:35 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_info(char *s,t_map *map)
{
	int	fd;
	char	*line;
	int		i;
	int		k;

	map->size = 0;
	map->width = 0;
	fd = open(s, O_RDONLY);
	k = 0;
	while(get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (ft_isdigit(line[i]) == TRUE)
			{
				map->size++;
				if (k != 1)
					map->width++;
			}
			i++;
		}	
		k = 1;
	}
	close(fd);
}
