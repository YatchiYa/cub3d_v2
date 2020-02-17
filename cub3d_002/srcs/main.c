#include "wolf3d.h"

void			map(t_game *g)
{
	g->worldmap[0] = "1111111111";
	g->worldmap[1] = "1003000201";
	g->worldmap[2] = "1003000201";
	g->worldmap[3] = "1100000001";
	g->worldmap[4] = "1000330001";
	g->worldmap[5] = "1000033001";
	g->worldmap[6] = "1004004001";
	g->worldmap[7] = "1104444001";
	g->worldmap[8] = "1000000001";
	g->worldmap[9] = "1111111111";
}

int				close_win(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exitit("Exiting");
	return (0);
}


int				main(int argc, char **argv)
{
	t_game	*g;
	
	if (!argc && !argv)
		return (0);
	if (!(g = (t_game *)malloc(sizeof(t_game))))
		return (0);
	map(g);
	makewindow(g);
}
