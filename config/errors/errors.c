
#include <stdlib.h>
#include "errors.h"

int exit_error(t_game *game, char const *str)
{
	if (str)
		write(0, str, ft_strlen(str));
	exit_game(game, EXIT_FAILURE);
	return (EXIT_FAILURE);
}