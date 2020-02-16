/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:29:44 by ielouazz          #+#    #+#             */
/*   Updated: 2019/04/17 21:09:09 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}
