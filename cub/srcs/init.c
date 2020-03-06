/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/03/05 18:34:03 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <string.h>

void		import_textures_3(t_game *g, int x, int y)
{
	if (!(g->tex_arr[8].img = mlx_xpm_file_to_image(g->mlx,
					"xpm/pillar.xpm", &x, &y)))
		exitit_2("Error :\n error texture wall,", g);
	g->tex_arr[8].data = mlx_get_data_addr(g->tex_arr[8].img,
							&g->tex_arr[8].bpp, &g->tex_arr[8].sizeline,
							&g->tex_arr[8].endian);
	if (g->ft_texture != NULL)
	{
		if (!(g->tex_arr[6].img = mlx_xpm_file_to_image(g->mlx,
						g->ft_texture, &x, &y)))
			exitit_2("Error :\n please specify floor textures ! needed,", g);
		g->tex_arr[6].data = mlx_get_data_addr(g->tex_arr[6].img,
							&g->tex_arr[6].bpp, &g->tex_arr[6].sizeline,
							&g->tex_arr[6].endian);
	}
}

void		import_textures_2(t_game *g, int x, int y)
{
	g->tex_arr[4].data = mlx_get_data_addr(g->tex_arr[4].img,
							&g->tex_arr[4].bpp, &g->tex_arr[4].sizeline,
							&g->tex_arr[4].endian);
	if (!(g->tex_arr[5].img = mlx_xpm_file_to_image(g->mlx, "xpm/redbrick.xpm",
			&x, &y)))
		exitit_2("Error :\n error texture wall,", g);
	g->tex_arr[5].data = mlx_get_data_addr(g->tex_arr[5].img,
							&g->tex_arr[5].bpp, &g->tex_arr[5].sizeline,
							&g->tex_arr[5].endian);
	if (!(g->tex_arr[7].img = mlx_xpm_file_to_image(g->mlx,
					g->s_texture, &x, &y)))
		exitit_2("Error :\n error sprite wall,", g);
	g->tex_arr[7].data = mlx_get_data_addr(g->tex_arr[7].img,
							&g->tex_arr[7].bpp, &g->tex_arr[7].sizeline,
							&g->tex_arr[7].endian);
	import_textures_3(g, x, y);
}

void		import_textures(t_game *g)
{
	int x;
	int y;

	if (!(g->tex_arr[1].img = mlx_xpm_file_to_image(g->mlx, g->no_texture,
			&x, &y)))
		exitit_2("Error :\n error texture wall,", g);
	g->tex_arr[1].data = mlx_get_data_addr(g->tex_arr[1].img,
							&g->tex_arr[1].bpp, &g->tex_arr[1].sizeline,
							&g->tex_arr[1].endian);
	if (!(g->tex_arr[2].img = mlx_xpm_file_to_image(g->mlx,
					g->so_texture, &x, &y)))
		exitit_2("Error :\n error texture wall,", g);
	g->tex_arr[2].data = mlx_get_data_addr(g->tex_arr[2].img,
							&g->tex_arr[2].bpp, &g->tex_arr[2].sizeline,
							&g->tex_arr[2].endian);
	if (!(g->tex_arr[3].img = mlx_xpm_file_to_image(g->mlx,
					g->ea_texture, &x, &y)))
		exitit_2("Error :\n error texture wall,", g);
	g->tex_arr[3].data = mlx_get_data_addr(g->tex_arr[3].img,
							&g->tex_arr[3].bpp, &g->tex_arr[3].sizeline,
							&g->tex_arr[3].endian);
	if (!(g->tex_arr[4].img = mlx_xpm_file_to_image(g->mlx, g->we_texture,
			&x, &y)))
		exitit_2("Error :\n error texture wall,", g);
	import_textures_2(g, x, y);
}

void		init_game_2(t_game *g)
{
	int direction;

	if (g->r_resolution == NULL)
		exitit_2("Error :\n no resolution \n", g);
	if ((direction = find_start_position(g)) != 0)
		set_direction(g, direction);
	else
		exitit_2("Error :\n no start position or > 2 \n", g);
	if (find_sprite(g) == 0)
		exitit_2("Error :\n no sprite position \n", g);
	if (g->c_color == NULL || g->f_color == NULL)
		exitit_2("Error :\n no color \n", g);
	check_texture_extension(g);
	import_textures(g);
}

void		init_game(t_game *g)
{
	g->posx = 6;
	g->posy = 8;
	g->dirx = -1;
	g->diry = 0;
	g->planex = 0;
	g->planey = 0.66;
	g->time = 0;
	g->oldtime = 0;
	g->w = 0;
	g->h = 0;
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
	g->c_color = NULL;
	g->f_color = NULL;
	g->r_resolution = NULL;
}
