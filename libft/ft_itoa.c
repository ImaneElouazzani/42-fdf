/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:09:42 by ielouazz          #+#    #+#             */
/*   Updated: 2019/04/19 23:41:37 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		num;
	size_t	nb;

	nb = (size_t)n;
	num = ft_nbrlen(n);
	if (!(s = (char *)malloc(sizeof(char) * (num + 1))))
		return (0);
	s[num--] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		nb = -1 * (size_t)n;
	}
	else if (n == 0)
		s[0] = '0';
	while (nb)
	{
		s[num--] = nb % 10 + '0';
		nb /= 10;
	}
	return (s);
}
