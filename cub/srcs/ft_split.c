/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:43:10 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/31 12:21:04 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	clear_tab(char **str, t_game *g)
{
	int	i;

	i = 0;
	while (i < g->rows)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int		ft_count_index(char const *s, char c)
{
	unsigned int	index;

	index = 0;
	while (*s)
	{
		if (*s != c && *s != '\0' && (*(s + 1) == c || *(s + 1) == '\0'))
			index++;
		s++;
	}
	return (index);
}

int		ft_malloc_index(char **tab, char const *s, char c, unsigned int index)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(tab[index] = malloc(sizeof(char) * (i + 1))))
	{
		i = 0;
		while (i < index)
			free(tab[i++]);
		free(tab);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char				**tab;
	unsigned int		i;
	unsigned int		index;
	unsigned int		words;

	index = 0;
	if (!s || !(tab = malloc(sizeof(char *) * (ft_count_index(s, c) + 1))))
		return (NULL);
	words = ft_count_index(s, c);
	while (*s && index < words)
	{
		while (*s && *s == c)
			s++;
		if (!ft_malloc_index(tab, s, c, index))
			return (NULL);
		i = 0;
		while (*s && *s != c)
			tab[index][i++] = *s++;
		tab[index++][i] = '\0';
	}
	tab[index] = 0;
	return (tab);
}
