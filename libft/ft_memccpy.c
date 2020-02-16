/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:57:14 by ielouazz          #+#    #+#             */
/*   Updated: 2019/04/21 21:37:09 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char *s;
	unsigned char		b;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	b = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == b)
			return (&d[i + 1]);
		i++;
	}
	return (NULL);
}
