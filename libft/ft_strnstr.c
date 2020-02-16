/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:36:47 by ielouazz          #+#    #+#             */
/*   Updated: 2019/04/15 15:29:04 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char *)s);
	i = 0;
	while (s[i] && i < len)
	{
		j = 0;
		if (s[i] == to_find[j])
		{
			while (i + j < len && s[i + j] && s[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (&(((char*)s)[i]));
		}
		i++;
	}
	return (NULL);
}
