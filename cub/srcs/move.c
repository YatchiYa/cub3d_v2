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
#include <stdio.h>

void	upmove(t_game *g)
{
	int x;
	int y;

	x = (int)(g->posx + g->dirx * g->movespeed);
	y = (int)(g->posy + g->diry * g->movespeed);
	if (g->upkey == 1 && g->downkey == 0)
	{
		if (g->wd[x][y] == 0)
		{
			g->posx += g->dirx * g->movespeed;
			g->posy += g->diry * g->movespeed;
			redraw(g);
		}
	}
}

void	downmove(t_game *g)
{
	int x;
	int y;

	x = (int)(g->posx - g->dirx * g->movespeed);
	y = (int)(g->posy - g->diry * g->movespeed);
	if (g->downkey == 1 & g->upkey == 0)
	{
		if (g->wd[x][y] == 0)
		{
			g->posx -= g->dirx * g->movespeed;
			g->posy -= g->diry * g->movespeed;
			redraw(g);
		}
	}
}

void	rightmove(t_game *g)
{
	if (g->rightkey == 1 && g->leftkey == 0)
	{
		g->olddirx = g->dirx;
		g->dirx = g->dirx * cos(-g->rotspeed) - g->diry * sin(-g->rotspeed);
		g->diry = g->olddirx * sin(-g->rotspeed) + g->diry * cos(-g->rotspeed);
		g->oldplanex = g->planex;
		g->planex = g->planex * cos(-g->rotspeed) -
			g->planey * sin(-g->rotspeed);
		g->planey = g->oldplanex * sin(-g->rotspeed) +
			g->planey * cos(-g->rotspeed);
		redraw(g);
	}
}

void	leftmove(t_game *g)
{
	if (g->leftkey == 1 && g->rightkey == 0)
	{
		g->olddirx = g->dirx;
		g->dirx = g->dirx * cos(g->rotspeed) - g->diry * sin(g->rotspeed);
		g->diry = g->olddirx * sin(g->rotspeed) +
			g->diry * cos(g->rotspeed);
		g->oldplanex = g->planex;
		g->planex = g->planex * cos(g->rotspeed) - g->planey * sin(g->rotspeed);
		g->planey = g->oldplanex * sin(g->rotspeed) +
			g->planey * cos(g->rotspeed);
		redraw(g);
	}
}

int		keyhooks(int key, t_game *g)
{
	(void)(g);
	if (key == 53)
		close_win(g);
	if (g->upkey == 1)
		upmove(g);
	if (g->downkey == 1)
		downmove(g);
	if (g->leftkey == 1)
		leftmove(g);
	if (g->rightkey == 1)
		rightmove(g);
	if (g->rk_move == 1)
		right_move(g);
	if (g->lf_move == 1)
		letf_move(g);
	if (g->speedup == 1 && (g->upkey == 1 || g->downkey == 1))
		speedmove(g);
	return (0);
}
