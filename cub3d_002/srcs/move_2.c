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

void	right_move(t_game *g)
{
	int x;
	int y;

	x = (int)(g->posx + g->diry * g->movespeed);
	y = (int)(g->posy - g->dirx * g->movespeed);
	if (g->rk_move == 1)
	{
		if (g->worldmap[x][y] == '0')
		{
			g->posy -= g->dirx * g->movespeed;
			g->posx += g->diry * g->movespeed;
			redraw(g);
		}
	}
}

void	letf_move(t_game *g)
{
	int x;
	int y;

	x = (int)(g->posx - g->diry * g->movespeed);
	y = (int)(g->posy + g->dirx * g->movespeed);
	if (g->lf_move == 1)
	{
		if (g->worldmap[x][y] == '0')
		{
			g->posy += g->dirx * g->movespeed;
			g->posx -= g->diry * g->movespeed;
			redraw(g);
		}
	}
}

void	speedmove(t_game *g)
{
	g->movespeed = 0.20;
	redraw(g);
}
