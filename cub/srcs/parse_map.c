/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:44:28 by yarab             #+#    #+#             */
/*   Updated: 2020/03/05 18:38:11 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		count_check_columns(char const *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == ' ')
			j++;
		else
			return (0);
		i++;
	}
	return (1);
}

int		check_left_right_borders(t_str *map_buffer)
{
	int				i;
	int				first;
	int				last;

	if (!map_buffer)
		return (0);
	i = 0;
	while (map_buffer)
	{
		first = 0;
		while (map_buffer->content[first] == ' ')
			first++;
		last = ft_strlen(map_buffer->content) - 1;
		while (map_buffer->content[last] == ' ')
			last--;
		if (map_buffer->content[first] != '1'
			|| map_buffer->content[last] != '1')
			return (0);
		map_buffer = map_buffer->next;
		i++;
	}
	return (1);
}

int		check_top_bottom_borders(t_str *map_buffer)
{
	int		first_line;
	int		last_line;
	t_str	*last;

	if (!map_buffer)
		return (0);
	first_line = count_check_columns(map_buffer->content);
	last = str_last(map_buffer);
	if (last)
		last_line = count_check_columns(last->content);
	else
		last_line = 0;
	if (first_line == 0 || last_line == 0)
		return (0);
	return (1);
}

int		check_valid(t_game *g, t_str *map_buffer)
{
	int		i;
	t_str	*first;

	first = map_buffer;
	while (map_buffer)
	{
		i = 0;
		while (map_buffer->content[i])
		{
			if (!ft_in_set(map_buffer->content[i], VALID_MAP_CHARACTERS))
				return (0);
			i++;
		}
		map_buffer = map_buffer->next;
	}
	map_buffer = first;
	if (cc(g, map_buffer) == 0)
		return (0);
	return (1);
}

int		ft_check_map(t_game *game, t_str *map_buffer)
{
	int		i;

	i = 0;
	if (check_top_bottom_borders(map_buffer) == 0
			|| (check_left_right_borders(map_buffer) == 0)
			|| check_valid(game, map_buffer) == 0)
		return (0);
	if (!(game->wd = (int**)malloc(sizeof(int*) * (game->rows))))
		return (0);
	while (i < game->rows)
	{
		if (!(game->wd[i] = (int*)malloc(sizeof(int) * (game->columns))))
			return (0);
		ft_fill_tab(game->wd[i], map_buffer);
		map_buffer = map_buffer->next;
		i++;
	}
	return (1);
}
