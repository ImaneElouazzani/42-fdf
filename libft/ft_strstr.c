/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:01:45 by ielouazz          #+#    #+#             */
/*   Updated: 2019/04/07 15:32:20 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *to_find)
{
	int i;
	int j;

	if (to_find[0] == '\0')
		return ((char *)s);
	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] == to_find[j])
		{
			while (s[i + j] && s[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (&(((char *)s)[i]));
		}
		i++;
	}
	return (NULL);
}
