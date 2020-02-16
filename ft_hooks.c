/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <ielouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:06:58 by ielouazz          #+#    #+#             */
/*   Updated: 2020/02/15 13:59:39 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		change_projection(int keycode, void *my_msg)
{
	(void)my_msg;
	printf("msg du serveur x %d\n", keycode);
	return (0);
}
