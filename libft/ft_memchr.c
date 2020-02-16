/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:52:50 by ielouazz          #+#    #+#             */
/*   Updated: 2019/04/21 21:38:21 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	b;

	i = 0;
	str = (unsigned char *)s;
	b = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == b)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
