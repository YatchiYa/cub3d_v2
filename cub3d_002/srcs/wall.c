/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/02/27 16:43:17 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			draw_wallxx(int x, int start, int end, t_game *t)
{
	if (t->texture == 1)
	{
		t->id = t->wd[t->mapx][t->mapy];
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

void			draw_floor_c(int x, t_game *t)
{
	t->y = t->drawend - 1;
	if (x < t->w && t->y < t->h)
		while (++t->y < t->h)
		{
			t->color = t->F_color[0];
			t->color = (t->color << 8) + t->F_color[1];
			t->color = (t->color << 8) + t->F_color[2];
			put_pxl_to_img(t, x, t->y, t->color);
		}
}

void			draw_sky_floor(int x, t_game *t)
{
	if (t->texture == 0)
	{
		if (t->drawstart > 0)
		{
			t->y = -1;
			if (x < t->w && t->y < t->h)
				while (++t->y < t->drawstart)
				{
					t->color = t->C_color[0];
					t->color = (t->color << 8) + t->C_color[1];
					t->color = (t->color << 8) + t->C_color[2];
					put_pxl_to_img(t, x, t->y, t->color);
				}
		}
		if (t->drawend > 0)
			draw_floor_c(x, t);
	}
}
