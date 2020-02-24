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
#include <math.h>
#include <string.h>

void		floor_c(t_game *g)
{
	int y;

	g->distWall = g->perpwalldist;
	g->distPlayer = 0.0;
	if (g->drawend < 0)
		g->drawend = g->h;
	y = g->drawend;
	while (++y < g->h)
	{
		g->currentDist = g->h / (2.0 * y - g->h);
		g->weight = (g->currentDist - g->distPlayer) /
			(g->distWall - g->distPlayer);
		g->currentFloorX = g->weight * g->floorXWall +
			(1.0 - g->weight) * g->posx;
		g->currentFloorY = g->weight * g->floorYWall +
			(1.0 - g->weight) * g->posy;
		g->floorTexX = (int)(g->currentFloorX * texWidth) &
			(texWidth - 1);
		g->floorTexY = (int)(g->currentFloorY * texHeight) &
			(texHeight - 1);
		ft_memcpy(g->imgpoke + 4 * WIDTH * y + g->x * 4,
				&g->tex_arr[6].data[g->floorTexY % texWidth *
				g->tex_arr[6].sizeline +
				g->floorTexX % texWidth * g->tex_arr[6].bpp / 8], sizeof(int));
	}
}

void		sky_c(t_game *g, int color)
{
	int y;

	y = 0;
	g->distWall = g->perpwalldist;
	g->distPlayer = 0.0;
	if (g->drawend < 0)
		g->drawend = g->h;
	y = 0;
	while (++y < g->drawstart)
	{
		g->currentDist = g->h / (2.0 * y - g->h);
		g->weight = (g->currentDist - g->distPlayer) /
			(g->distWall - g->distPlayer);
		g->currentFloorX = g->weight * g->floorXWall +
			(1.0 - g->weight) * g->posx;
		g->currentFloorY = g->weight * g->floorYWall +
			(1.0 - g->weight) * g->posy;
		g->floorTexX = (int)(g->currentFloorX * texWidth) &
			(texWidth - 1);
		g->floorTexY = (int)(g->currentFloorY * texHeight) &
			(texHeight - 1);
		ft_memcpy(g->imgpoke + 4 * WIDTH * y + g->x * 4,
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
		g->floorXWall = g->mapx;
		g->floorYWall = g->mapy + g->x_wall;
	}
	else if (g->side == 0 && g->raydirx < 0)
	{
		g->floorXWall = g->mapx + 1.0;
		g->floorYWall = g->mapy + g->x_wall;
	}
	else if (g->side == 1 && g->raydiry > 0)
	{
		g->floorXWall = g->mapx + g->x_wall;
		g->floorYWall = g->mapy;
	}
	else
	{
		g->floorXWall = g->mapx + g->x_wall;
		g->floorYWall = g->mapy + 1.0;
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
