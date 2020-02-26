/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/02/21 14:13:49 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycast_init(t_game *g)
{
	g->camerax = 2 * g->x / (double)g->w - 1;
	g->rayposx = g->posx;
	g->rayposy = g->posy;
	g->raydirx = g->dirx + g->planex * g->camerax;
	g->raydiry = g->diry + g->planey * g->camerax;
	g->mapx = (int)g->rayposx;
	g->mapy = (int)g->rayposy;
	g->deltadistx = sqrt(1 + (g->raydiry *
				g->raydiry) / (g->raydirx * g->raydirx));
	g->deltadisty = sqrt(1 + (g->raydirx *
				g->raydirx) / (g->raydiry * g->raydiry));
	g->hit = 0;
}

void	raycast_dist(t_game *g)
{
	if (g->raydirx < 0)
	{
		g->stepx = -1;
		g->sidedistx = (g->rayposx - g->mapx) * g->deltadistx;
	}
	else
	{
		g->stepx = 1;
		g->sidedistx = (g->mapx + 1.0 - g->rayposx) * g->deltadistx;
	}
	if (g->raydiry < 0)
	{
		g->stepy = -1;
		g->sidedisty = (g->rayposy - g->mapy) * g->deltadisty;
	}
	else
	{
		g->stepy = 1;
		g->sidedisty = (g->mapy + 1.0 - g->rayposy) * g->deltadisty;
	}
}

void	raycat_object(t_game *g)
{
	while (g->hit == 0)
	{
		if (g->sidedistx < g->sidedisty)
		{
			g->sidedistx += g->deltadistx;
			g->mapx += g->stepx;
			g->side = 0;
		}
		else
		{
			g->sidedisty += g->deltadisty;
			g->mapy += g->stepy;
			g->side = 1;
		}
		if (g->wd[g->mapx][g->mapy] > 0)
			g->hit = 1;
	}
	if (g->side == 0)
		g->perpwalldist = (g->mapx - g->rayposx +
				(1 - g->stepx) / 2) / g->raydirx;
	else
		g->perpwalldist = (g->mapy - g->rayposy +
				(1 - g->stepy) / 2) / g->raydiry;
	g->lineheight = (int)(g->h / g->perpwalldist);
	g->drawstart = -(g->lineheight) / 2 + g->h / 2;
}

void	raycast_draw(t_game *g)
{
	g->drawstart = -(g->lineheight) / 2 + g->h / 2;
	if (g->drawstart < 0)
		g->drawstart = 0;
	g->drawend = g->lineheight / 2 + g->h / 2;
	if (g->drawend >= g->h)
		g->drawend = g->h - 1;
	if (g->side == 1)
		g->color = 0xdd8800;
	else
		g->color = 0x00FF00;
	draw_wallxx(g->x, g->drawstart - 1, g->drawend, g);
	if (g->texture == 1)
	{
		floor_cast(g);
		sky_cast(g);
	}
	else
		draw_sky_floor(g->x, g);
}

void	raycast_procjection(t_game *g)
{
	t_raysprite	rs;

	g->x = -1;
	while (++g->x < g->w)
	{
		raycast_init(g);
		raycast_dist(g);
		raycat_object(g);
		raycast_draw(g);
		g->zbuffer[g->x] = g->perpwalldist;
	}
	rs.i = 0;
	while (rs.i < 3)
	{
		ray_sprite(g, &rs);
		draw_sprite(g, g, &rs);
		rs.i++;
	}
}
