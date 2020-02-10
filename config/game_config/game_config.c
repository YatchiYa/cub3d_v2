
#include "../../client/cub3d.h"
#include "game_config.h"
#include "../parser/config_parse.h"
# include <math.h>
# include "../mlx/mlx.h"


void    init_config(t_game_config *game_config)
{
    game_config->height = 700;
    game_config->width = 480;
    game_config->NO_texture = NULL;
    game_config->SO_texture = NULL;
    game_config->WE_texture = NULL;
    game_config->EA_texture = NULL;
    game_config->ST_texture = NULL;
    game_config->FT_texture = NULL;
    game_config->S_texture = NULL;
    game_config->F_color = NULL;
    game_config->C_color = NULL;
    game_config->maps = NULL;
}


int 	init_game(t_game *game, int screen)
{
	game->screen_flag = screen;
	init_config(&game->game_config);
	
	return (0);
}

int 	exit_game(t_game *game, int code)
{
	return (0);
}


int	fnish_init_game(t_game *game)
{

  /*void *mlx;
  void *window;
  
  mlx = mlx_init();
  window = mlx_new_window(mlx, 1000, 1000, "Title");
  
  mlx_loop(mlx);
  */
}










int		ft_parse_line(t_game_config *game_config, char *line, t_str **map_buffer, t_str *first_elem)
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
		return (parse_map(game_config, line, map_buffer, first_elem));
	else if (line[0] == ' ' || line[0] == '\n' || line[0] == '\0')
		return (1);
	else
		return (0);
}

void	affichage(t_str *liste)
{
	t_str *tmp = liste;

	while (tmp->next != NULL)
	{
		printf(" \n debug %s\n", tmp->content);
		tmp = tmp->next;
	}
		printf(" \n debug %s\n", tmp->content);
}

int 	parse_game_config(t_game_config *game_config, char *path)
{
	int			fd;
	char		*line;
	t_str		*map_buffer;
	t_str		first_elem;
	int			ret;

	map_buffer = NULL;
	if (ft_endwith(path, ".cub") == 0)
		return (0);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	int k = -1;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ft_parse_line(game_config, line, &map_buffer, &first_elem) == 0)
			return (0);
		free(line);
	}
	if (ret == 0 && ft_strlen(line) > 0 && str_add_back(&map_buffer, ft_strdup(line)))
		;
	free(line);
	close(fd);
	if (ft_check_map(game_config, map_buffer) == 0)
		return (0);
	// affichage(map_buffer);
	return (1);
}