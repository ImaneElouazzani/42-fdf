/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:57:59 by ielouazz          #+#    #+#             */
/*   Updated: 2019/04/22 13:23:57 by ielouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compteur(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*word_dup(char const *s, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(new = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (compteur(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j++] = word_dup(&s[i], c);
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
