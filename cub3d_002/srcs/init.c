/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/02/24 18:27:41 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <string.h>

void		import_textures_2(t_game *g, int x, int y)
{
	g->tex_arr[4].data = mlx_get_data_addr(g->tex_arr[4].img,
							&g->tex_arr[4].bpp,
							&g->tex_arr[4].sizeline,
							&g->tex_arr[4].endian);
	if (!(g->tex_arr[5].img = mlx_xpm_file_to_image(g->mlx, "xpm/redbrick.xpm",
			&x, &y)))
		exitit("Error :\n error texture wall");
	g->tex_arr[5].data = mlx_get_data_addr(g->tex_arr[5].img,
							&g->tex_arr[5].bpp,
							&g->tex_arr[5].sizeline,
							&g->tex_arr[5].endian);
	if (!(g->tex_arr[6].img = mlx_xpm_file_to_image(g->mlx, "xpm/sand.xpm", &x, &y)))
		exitit("Error :\n error texture wall");
	g->tex_arr[6].data = mlx_get_data_addr(g->tex_arr[6].img,
							&g->tex_arr[6].bpp,
							&g->tex_arr[6].sizeline,
							&g->tex_arr[6].endian);
	if (!(g->tex_arr[7].img = mlx_xpm_file_to_image(g->mlx, "xpm/barrel.xpm", &x, &y)))
		exitit("Error :\n error texture wall");
	g->tex_arr[7].data = mlx_get_data_addr(g->tex_arr[7].img,
							&g->tex_arr[7].bpp,
							&g->tex_arr[7].sizeline,
							&g->tex_arr[7].endian);
	if (!(g->tex_arr[8].img = mlx_xpm_file_to_image(g->mlx, "xpm/pillar.xpm", &x, &y)))
		exitit("Error :\n error texture wall");
	g->tex_arr[8].data = mlx_get_data_addr(g->tex_arr[8].img,
							&g->tex_arr[8].bpp,
							&g->tex_arr[8].sizeline,
							&g->tex_arr[8].endian);
}

void		import_textures(t_game *g)
{
	int x;
	int y;

	if (!(g->tex_arr[1].img = mlx_xpm_file_to_image(g->mlx, "xpm/redbrick.xpm",
			&x, &y)))
		exitit("Error :\n error texture wall");
	g->tex_arr[1].data = mlx_get_data_addr(g->tex_arr[1].img,
							&g->tex_arr[1].bpp,
							&g->tex_arr[1].sizeline,
							&g->tex_arr[1].endian);
	if (!(g->tex_arr[2].img = mlx_xpm_file_to_image(g->mlx, "xpm/grey.xpm", &x, &y)))
		exitit("Error :\n error texture wall");
	g->tex_arr[2].data = mlx_get_data_addr(g->tex_arr[2].img,
							&g->tex_arr[2].bpp,
							&g->tex_arr[2].sizeline,
							&g->tex_arr[2].endian);
	if (!(g->tex_arr[3].img = mlx_xpm_file_to_image(g->mlx, "xpm/mossy.xpm", &x, &y)))
		exitit("Error :\n error texture wall");
	g->tex_arr[3].data = mlx_get_data_addr(g->tex_arr[3].img,
							&g->tex_arr[3].bpp,
							&g->tex_arr[3].sizeline,
							&g->tex_arr[3].endian);
	if (!(g->tex_arr[4].img = mlx_xpm_file_to_image(g->mlx, "xpm/bluestone.xpm",
			&x, &y)))
		exitit("Error :\n error texture wall");
	import_textures_2(g, x, y);
}

void		init_game_2(t_game *g)
{
	int direction;

	if ((direction = find_start_position(g)) != 0)
		set_direction(g, direction);
	else
		exitit("Error :\n no start position \n please specify : W/E/S/N in your map");
	if (find_sprite(g) == 0)
		exitit("Error :\n no sprite position \n please specify  at least one sprite : S");
	import_textures(g);
}

void		init_game(t_game *g)
{
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
	init_game_2(g);
}
