/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:44:28 by yarab             #+#    #+#             */
/*   Updated: 2020/03/06 19:55:19 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		test(int i, int j, char **str)
{
	if (str[i][j] == ' ')
	{
		if (str[i - 1][j] == '0' || str[i - 1][j] == 'S'
				|| str[i - 1][j] == 'N'
				|| str[i - 1][j] == 'E' || str[i - 1][j] == 'W')
			return (0);
		else if (str[i][j + 1] == '0' || str[i][j + 1] == 'S'
				|| str[i][j + 1] == 'N'
				|| str[i][j + 1] == 'E' || str[i][j + 1] == 'W')
			return (0);
	}
	else if (str[i][j] == '0' || str[i][j] == 'S' || str[i][j] == 'N'
				|| str[i][j] == 'E' || str[i][j] == 'W')
	{
		if (str[i - 1][j] == ' ' || str[i][j + 1] == ' ')
			return (0);
	}
	return (1);
}

int		checkk(char **str, t_game *g)
{
	int	i;
	int	j;

	i = 1;
	while (i < g->rows)
	{
		j = 0;
		while (j < g->columns)
		{
			if (test(i, j, str) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	f1(t_str *map_buffer, char **str, t_game *g)
{
	int		i;
	int		j;
	t_str	*first;

	first = map_buffer;
	i = 0;
	while (map_buffer)
	{
		j = 0;
		while (map_buffer->content[j] != '\0')
		{
			str[i][j] = map_buffer->content[j];
			j++;
		}
		while (j < g->columns)
		{
			str[i][j] = ' ';
			j++;
		}
		str[i][j] = '\0';
		i++;
		map_buffer = map_buffer->next;
	}
	map_buffer = first;
}

int		cc(t_game *g, t_str *map_buffer)
{
	int		i;
	char	**str;

	i = 0;
	if (!(str = (char**)malloc(sizeof(char*) * (g->rows))))
		return (0);
	while (i < g->rows)
	{
		if (!(str[i] = malloc(sizeof(char) * (g->columns + 1))))
			return (0);
		i++;
	}
	f1(map_buffer, str, g);
	if (checkk(str, g) == 0)
	{
		clear_tab(str, g);
		return (0);
	}
	clear_tab(str, g);
	return (1);
}
