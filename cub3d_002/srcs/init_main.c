#include "wolf3d.h"

void	player(t_game *g)
{
	g->healthbar = mlx_xpm_file_to_image(g->mlx, "./xpm/healthbar.xpm",
			&(g->health_w), &(g->health_h));
	g->imghealth = (int*)mlx_get_data_addr(g->healthbar, &(g->health_bpp),
			&(g->health_sl), &(g->health_end));
	mlx_put_image_to_window(g->mlx, g->win, g->healthbar, 0, 0);
}


int		repeat(t_game *g)
{
	mlx_hook(g->win, 2, 0, key_press, g);
	mlx_hook(g->win, 3, 0, key_release, g);
	mlx_hook(g->win, 17, 0, close_win, g);
	return (0);
}

void	exitit(char *str)
{
	printf("%s\n",str);
	exit(0);
}