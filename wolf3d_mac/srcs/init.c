#include "wolf3d.h"


void	init_game(t_game *g)
{
	g->posx = 6;
	g->posy = 8;
	g->dirx = -1;
	g->diry = 0;
	g->planex = 0;
	g->planey = 0.66;
	g->time = 0;
	g->oldtime = 0;
	g->w = WIDTH;
	g->h = HEIGHT;
	g->upkey = 0;
	g->downkey = 0;
	g->leftkey = 0;
	g->rightkey = 0;
	g->rk_move = 0;
	g->lf_move = 0;
	g->rotspeed = .11;
	g->movespeed = .11;
	g->tx_x = 0;
	g->tx_y = 0;
}

