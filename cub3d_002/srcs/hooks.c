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

void	cahnge_texture(t_game *g, int key)
{
	if (key == 17 && g->texture == 0)
	{
		g->texture = 1;
		redraw(g);
	}
	else if (key == 17 && g->texture == 1)
	{
		g->texture = 0;
		redraw(g);
	}
}

int		key_press(int key, t_game *g)
{
	if (key == 126 || key == 13)
		g->upkey = 1;
	else if (key == 125 || key == 1)
		g->downkey = 1;
	else if (key == 123)
		g->leftkey = 1;
	else if (key == 124)
		g->rightkey = 1;
	else if (key == 0)
		g->lf_move = 1;
	else if (key == 2)
		g->rk_move = 1;
	else if (key == 257)
		g->speedup = 1;
	keyhooks(key, g);
	cahnge_texture(g, key);
	return (0);
}

int		key_release(int key, t_game *g)
{
	if (key == 126 || key == 13)
		g->upkey = 0;
	else if (key == 125 || key == 1)
		g->downkey = 0;
	else if (key == 123)
		g->leftkey = 0;
	else if (key == 124)
		g->rightkey = 0;
	else if (key == 2)
		g->rk_move = 0;
	else if (key == 0)
		g->lf_move = 0;
	else if (key == 257)
	{
		g->speedup = 0;
		g->movespeed = .07;
	}
	keyhooks(key, g);
	return (0);
}
