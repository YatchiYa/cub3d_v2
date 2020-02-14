#include "wolf3d.h"


int		key_press(int key, t_game *g)
{
	if (key == 126 || key == 13)
		g->upkey = 1;
	else if (key == 125 || key == 1)
		g->downkey = 1;
	else if (key == 123)
		g->leftkey = 1;
	else if (key == 124)
		g->rightkey = 1;
	else if (key == 0)
		g->lf_move = 1;
	else if (key == 2)
		g->rk_move = 1;
	keyhooks(key, g);
	return (0);
}

int		key_release(int key, t_game *g)
{
	if (key == 126 || key == 13)
		g->upkey = 0;
	else if (key == 125 || key == 1)
		g->downkey = 0;
	else if (key == 123)
		g->leftkey = 0;
	else if (key == 124)
		g->rightkey = 0;
	else if (key == 2)
		g->rk_move = 0;
	else if (key == 0)
		g->lf_move = 0;
	keyhooks(key, g);
	return (0);
}



void	redraw(t_game *g)
{
	mlx_destroy_image(g->mlx, g->img);
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->imgpoke = (int*)mlx_get_data_addr(g->img, &(g->bpp),
			&(g->sl), &(g->end));
	raycast_procjection(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	player(g);
}


void	makewindow(t_game *g)
{
	g->mlx = mlx_init();
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Wolf3D");

	g->imgpoke = (int*)mlx_get_data_addr(g->img, &g->bpp, &(g->sl), &(g->end));
	
	init_game(g);
	raycast_procjection(g);

	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	player(g);
	mlx_loop_hook(g->mlx, repeat, g);
	mlx_loop(g->mlx);
}
