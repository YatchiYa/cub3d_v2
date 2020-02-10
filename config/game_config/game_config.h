


#ifndef GAME_CONFIG_H
# define GAME_CONFIG_H

# include "../utils/utils.h"


int exit_game(t_game *game, int code);
int init_game(t_game *game, int screen);
void    init_config(t_game_config *game_config);

int parse_game_config(t_game_config *game_config, char *path);
int parse_NOSOWEEA(t_game_config *game_config, char *line, char *mode);
int parse_FC_color(t_game_config *game_config, char *line, char mode);
int fill_rgb_color(t_game_config *game_config, char *str, char mode);

#endif
