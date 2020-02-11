
#ifndef CONFIG_ALL_H
# define CONFIG_ALL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>

# include "../mlx/mlx.h"
# include "../bin/config/config.h"


void			init_map(t_game *g);
unsigned int	colormagic(int i, double x, double y);
void	wall_color(t_game *g);
void	drawstuff1(t_game *g);
void	drawstuff2(t_game *g);
void	drawstuff3(t_game *g);
void	drawstuff4(t_game *g);
void	drawstuff(t_game *g);


#endif