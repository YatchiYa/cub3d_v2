#include "wolf3d.h"

void    import_textures(t_game *g)
{
    int x = 64;
    int y = 64;
    g->tex_arr[1].img = mlx_xpm_file_to_image(g->mlx, "xpm/redbrick.xpm", &x, &y);
	g->tex_arr[1].data = mlx_get_data_addr(g->tex_arr[1].img,
							&g->tex_arr[1].bpp,
							&g->tex_arr[1].sizeline,
							&g->tex_arr[1].endian);
    g->tex_arr[2].img = mlx_xpm_file_to_image(g->mlx, "xpm/grey.xpm", &x, &y);
	g->tex_arr[2].data = mlx_get_data_addr(g->tex_arr[2].img,
							&g->tex_arr[2].bpp,
							&g->tex_arr[2].sizeline,
							&g->tex_arr[2].endian);
    g->tex_arr[3].img = mlx_xpm_file_to_image(g->mlx, "xpm/mossy.xpm", &x, &y);
	g->tex_arr[3].data = mlx_get_data_addr(g->tex_arr[3].img,
							&g->tex_arr[3].bpp,
							&g->tex_arr[3].sizeline,
							&g->tex_arr[3].endian);
    g->tex_arr[4].img = mlx_xpm_file_to_image(g->mlx, "xpm/bluestone.xpm", &x, &y);
	g->tex_arr[4].data = mlx_get_data_addr(g->tex_arr[4].img,
							&g->tex_arr[4].bpp,
							&g->tex_arr[4].sizeline,
							&g->tex_arr[4].endian);

    g->tex_arr[5].img = mlx_xpm_file_to_image(g->mlx, "xpm/ceilling.xpm", &x, &y);
	g->tex_arr[5].data = mlx_get_data_addr(g->tex_arr[5].img,
							&g->tex_arr[5].bpp,
							&g->tex_arr[5].sizeline,
							&g->tex_arr[5].endian);


    g->tex_arr[6].img = mlx_xpm_file_to_image(g->mlx, "xpm/sand.xpm", &x, &y);
	g->tex_arr[6].data = mlx_get_data_addr(g->tex_arr[6].img,
							&g->tex_arr[6].bpp,
							&g->tex_arr[6].sizeline,
							&g->tex_arr[6].endian);
    g->tex_arr[7].img = mlx_xpm_file_to_image(g->mlx, "xpm/barrel.xpm", &x, &y);
	g->tex_arr[7].data = mlx_get_data_addr(g->tex_arr[7].img,
							&g->tex_arr[7].bpp,
							&g->tex_arr[7].sizeline,
							&g->tex_arr[7].endian);
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


	// definir l'angle de vue
	// 135 regarder vers le sud 
	// 0 vers le nord 
	// 67.5 vers l'est 
	// -67.5 vers l'ouest 
	
	g->olddirx = g->dirx;
		g->dirx = g->dirx * cos(-67.5) - g->diry * sin(-67.5);
		g->diry = g->olddirx * sin(-67.5) +
			g->diry * cos(-67.5);
		g->oldplanex = g->planex;
		g->planex = g->planex * cos(-67.5) - g->planey * sin(-67.5);
		g->planey = g->oldplanex * sin(-67.5) +
			g->planey * cos(-67.5);


    import_textures(g);
}

