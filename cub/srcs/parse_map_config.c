/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/02/27 16:51:47 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ff(t_game *game_config, char *line, t_str **map_buffer, int i)
{
	if (line[i] == 'F')
		return (parse_fc_color(game_config, &line[i + 1], 'F'));
	else if (line[i] == 'C')
		return (parse_fc_color(game_config, &line[i + 1], 'C'));
	else if (line[i] == '1')
		return (parse_map(line + i, map_buffer));
	else if (line[i] == ' ' || line[i] == '\n' || line[i] == '\0')
		return (1);
	else
		return (1);
}

int		ft_parse_line(t_game *game_config, char *line, t_str **map_buffer)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'R')
		return (parse_resolution(game_config, line));
	else if (line[i] == 'S' && line[i + 1] == 'T')
		return (parse_nosoweea(game_config, &line[i + 2], "ST"));
	else if (line[i] == 'N' && line[i + 1] == 'O')
		return (parse_nosoweea(game_config, &line[i + 2], "NO"));
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (parse_nosoweea(game_config, &line[i + 2], "SO"));
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (parse_nosoweea(game_config, &line[i + 2], "WE"));
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (parse_nosoweea(game_config, &line[i + 2], "EA"));
	else if (line[i] == 'S')
		return (parse_nosoweea(game_config, &line[i + 1], "S"));
	else if (line[i] == 'F' && line[i + 1] == 'T')
		return (parse_nosoweea(game_config, &line[i + 2], "FT"));
	else
		return (ff(game_config, line, map_buffer, i));
}
