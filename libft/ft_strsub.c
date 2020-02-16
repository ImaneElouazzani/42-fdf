/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:49:48 by ielouazz          #+#    #+#             */
/*   Updated: 2019/04/21 22:38:23 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(s1 = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len > 0)
	{
		s1[i] = s[start];
		i++;
		start++;
		len--;
	}
	s1[i] = '\0';
	return (s1);
}
