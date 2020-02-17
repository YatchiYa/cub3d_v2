#include "wolf3d.h"

void    import_textures(t_game *g)
{
    int x = 64;
    int y = 64;
    g->tex_arr[0].img = mlx_xpm_file_to_image(g->mlx, "xpm/wall2.xpm", &x, &y);
	g->tex_arr[0].data = mlx_get_data_addr(g->tex_arr[0].img,
							&g->tex_arr[0].bpp,
							&g->tex_arr[0].sizeline,
							&g->tex_arr[0].endian);

    g->tex_arr[1].img = mlx_xpm_file_to_image(g->mlx, "xpm/ceilling.xpm", &x, &y);
	g->tex_arr[1].data = mlx_get_data_addr(g->tex_arr[1].img,
							&g->tex_arr[1].bpp,
							&g->tex_arr[1].sizeline,
							&g->tex_arr[1].endian);


    g->tex_arr[2].img = mlx_xpm_file_to_image(g->mlx, "xpm/sand.xpm", &x, &y);
	g->tex_arr[2].data = mlx_get_data_addr(g->tex_arr[2].img,
							&g->tex_arr[2].bpp,
							&g->tex_arr[2].sizeline,
							&g->tex_arr[2].endian);
}

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
	g->rotspeed = .07;
	g->movespeed = .11;
	g->x_text = 0;
	g->y_text = 0;
	g->texture = 0;
	g->speedup = 0;
    import_textures(g);
}

