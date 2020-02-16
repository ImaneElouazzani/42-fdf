/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:26:43 by ielouazz          #+#    #+#             */
/*   Updated: 2019/04/21 22:20:39 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		a;
	int		b;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!(s3 = (char *)malloc(sizeof(char) * (a + b + 1))))
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcat(s3, s2);
	s3[a + b] = '\0';
	return (s3);
}
