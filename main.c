
#include "./client/cub3d.h"

int main(int argc, char **argv)
{
	t_game	game;
	int		screen;

    screen = 0;
    if (argc >= 2 && ft_strcmp(argv[1], "-save") == 0)
        screen = 1;
	if (argc < (2 + screen))
		return (exit_error(&game, "Error:\nno map specified.\n"));	
    init_game(&game, screen);
	if (parse_game_config(&game.game_config, argv[1 + screen]) == 0)
		return (exit_error(&game, "Error:\ninvalid map.\n"));
	
	//if (!fnish_init_game(&game))
	//	return (0);
	
	printf(" process with the game \n");
	
	return (EXIT_SUCCESS);
}