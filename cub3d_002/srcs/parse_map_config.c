/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/02/21 14:13:49 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_parse_line(t_game *game_config, char *line, t_str **map_buffer)
{
	if (line[0] == 'R')
		return (parse_resolution(game_config,line));
	else if (line[0] == 'S' && line[1] == 'T')
		return (parse_NOSOWEEA(game_config, &line[2], "ST"));
	else if (line[0] == 'N' && line[1] == 'O')
		return (parse_NOSOWEEA(game_config, &line[2], "NO"));
	else if (line[0] == 'S' && line[1] == 'O')
		return (parse_NOSOWEEA(game_config, &line[2], "SO"));
	else if (line[0] == 'W' && line[1] == 'E')
		return (parse_NOSOWEEA(game_config, &line[2], "WE"));
	else if (line[0] == 'E' && line[1] == 'A')
		return (parse_NOSOWEEA(game_config, &line[2], "EA"));
	else if (line[0] == 'S')
		return (parse_NOSOWEEA(game_config, &line[1], "S"));
	else if (line[0] == 'F' && line[1] == 'T')
		return (parse_NOSOWEEA(game_config, &line[2], "FT"));
	else if (line[0] == 'F')
		return (parse_FC_color(game_config, &line[1], 'F'));
	else if (line[0] == 'C')
		return (parse_FC_color(game_config, &line[1], 'C'));
	else if (line[0] == '1')
		return (parse_map(line, map_buffer));
	else if (line[0] == ' ' || line[0] == '\n' || line[0] == '\0')
		return (1);
	else
		return (1);
}

int 	parse_game_config(t_game *game, char *path)
{
	int			fd;
	char		*line;
	t_str		*map_buffer;
	int			ret;

	map_buffer = NULL;
	if (ft_endwith(path, ".cub") == 0)
        exitit(" not a valide map extension", game);
	if ((fd = open(path, O_RDONLY)) < 0)
        exitit(" can't open the file ", game);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ft_parse_line(game, line, &map_buffer) == 0)
        {
            free(line);
			return (0);
        }
		free(line);
	}
	if (ret == 0 && ft_strlen(line) > 0)
        str_add_back(&map_buffer, ft_strdup(line));
    game->columns = ft_strlen(line);
    game->rows = str_length(map_buffer);
	if (ft_check_map(game, map_buffer) == 0)
        exitit(" error map format ", game);
	free(line);
	close(fd);
	return (1);
}