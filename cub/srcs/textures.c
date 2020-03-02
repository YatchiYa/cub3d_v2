/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/02/24 18:09:18 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		floor_c(t_game *g)
{
	int y;

	g->distwall = g->perpwalldist;
	g->distplayer = 0.0;
	if (g->drawend < 0)
		g->drawend = g->h;
	y = g->drawend;
	while (++y < g->h)
	{
		g->currentdist = g->h / (2.0 * y - g->h);
		g->weight = (g->currentdist - g->distplayer) /
			(g->distwall - g->distplayer);
		g->currentfloorx = g->weight * g->floorxwall +
			(1.0 - g->weight) * g->posx;
		g->currentfloory = g->weight * g->floorywall +
			(1.0 - g->weight) * g->posy;
		g->floortexx = (int)(g->currentfloorx * 64) &
			(64 - 1);
		g->floortexy = (int)(g->currentfloory * 64) &
			(64 - 1);
		ft_memcpy(g->imgpoke + 4 * g->w * y + g->x * 4,
				&g->tex_arr[6].data[g->floortexy % 64 *
				g->tex_arr[6].sizeline +
				g->floortexx % 64 * g->tex_arr[6].bpp / 8], sizeof(int));
	}
}

void		sky_c(t_game *g, int color)
{
	int y;

	y = 0;
	g->distwall = g->perpwalldist;
	g->distplayer = 0.0;
	if (g->drawend < 0)
		g->drawend = g->h;
	y = 0;
	while (++y < g->drawstart)
	{
		g->currentdist = g->h / (2.0 * y - g->h);
		g->weight = (g->currentdist - g->distplayer) /
			(g->distwall - g->distplayer);
		g->currentfloorx = g->weight * g->floorxwall +
			(1.0 - g->weight) * g->posx;
		g->currentfloory = g->weight * g->floorywall +
			(1.0 - g->weight) * g->posy;
		g->floortexx = (int)(g->currentfloorx * 64) &
			(64 - 1);
		g->floortexy = (int)(g->currentfloory * 64) &
			(64 - 1);
		ft_memcpy(g->imgpoke + 4 * g->w * y + g->x * 4,
				&color, sizeof(int));
	}
}

void		floor_cx(t_game *g)
{
	if (g->side == 0)
		g->x_wall = g->posy + g->perpwalldist * g->raydiry;
	else
		g->x_wall = g->posx + g->perpwalldist * g->raydirx;
	g->x_wall -= floor((g->x_wall));
	if (g->side == 0 && g->raydirx > 0)
	{
		g->floorxwall = g->mapx;
		g->floorywall = g->mapy + g->x_wall;
	}
	else if (g->side == 0 && g->raydirx < 0)
	{
		g->floorxwall = g->mapx + 1.0;
		g->floorywall = g->mapy + g->x_wall;
	}
	else if (g->side == 1 && g->raydiry > 0)
	{
		g->floorxwall = g->mapx + g->x_wall;
		g->floorywall = g->mapy;
	}
	else
	{
		g->floorxwall = g->mapx + g->x_wall;
		g->floorywall = g->mapy + 1.0;
	}
}

void		floor_cast(t_game *g)
{
	floor_cx(g);
	floor_c(g);
}

void		sky_cast(t_game *g)
{
	int color;

	color = 0x0B2D4B;
	floor_cx(g);
	sky_c(g, color);
}
