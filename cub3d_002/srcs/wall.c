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

void			draw_wallxx(int x, int start, int end, t_game *t)
{
	if (t->texture == 1)
	{
		t->id = t->worldmap[t->mapx][t->mapy];
		if (t->side == 0)
			t->x_wall = t->rayposy + t->perpwalldist * t->raydiry;
		else
			t->x_wall = t->rayposx + t->perpwalldist * t->raydirx;
		t->x_text = (int)(t->x_wall * (double)(64));
		if (t->side == 0 && t->raydirx > 0)
			t->x_text = 64 - t->x_text - 1;
		if (t->side == 1 && t->raydiry < 0)
			t->x_text = 64 - t->x_text - 1;
		t->x_wall = floor(t->x_wall);
		t->x_text = abs(t->x_text);
	}
	t->color = wall_direction(t);
	while (++start < end)
		put_pxl_to_img(t, x, start, t->color);
}

void			draw_sky_floor(int x, t_game *t)
{
	if (t->texture == 0)
	{
		if (t->drawstart > 0)
		{
			t->y = -1;
			if (x < WIDTH && t->y < HEIGHT)
				while (++t->y < t->drawstart)
				{
					t->color = 0x66CCFF;
					put_pxl_to_img(t, x, t->y, t->color);
				}
		}
		if (t->drawend > 0)
		{
			t->y = t->drawend - 1;
			if (x < WIDTH && t->y < HEIGHT)
				while (++t->y < HEIGHT)
				{
					t->color = 0x06FF00;
					put_pxl_to_img(t, x, t->y, t->color);
				}
		}
	}
}
