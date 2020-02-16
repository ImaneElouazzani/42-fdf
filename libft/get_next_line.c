/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:15:44 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/06 12:09:29 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_rest(char *s1, char **line)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = NULL;
	while (s1[i] != '\n' && s1[i])
		i++;
	*line = ft_strsub(s1, 0, i);
	if (s1[i] == '\n')
		s2 = ft_strdup(s1 + i + 1);
	free(s1);
	return (s2);
}

int				get_next_line(const int fd, char **line)
{
	int				rd;
	char			buff[BUFF_SIZE + 1];
	static char		*str[4864];
	char			*tmp;

	if (fd < 0 || !line || BUFF_SIZE < 0 || fd > 4863)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (rd < 0)
		return (-1);
	if (rd == 0 && !ft_strlen(str[fd]))
		return (0);
	str[fd] = ft_rest(str[fd], line);
	return (1);
}
