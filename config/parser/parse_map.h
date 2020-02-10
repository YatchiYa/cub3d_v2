
#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include "../../client/cub3d.h"

# define DIRECTIONS "NSEW"
# define VALID_MAP_CHARACTERS " 01234NSEW"

int ft_check_map(t_game_config *game_config, t_str *map_buffer);
int check_valid(t_game_config *config, t_str *map_buffer);
int     parse_map(t_game_config *game_config, char *line, t_str **map_buffer, t_str *first_elem);

#endif