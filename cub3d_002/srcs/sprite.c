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

void	ray_sprite(t_game *e, t_raysprite *rs)
{
	rs->spritex = e->sprite[rs->i].x - e->posx;
	rs->spritey = e->sprite[rs->i].y - e->posy;
	rs->invdet = 1.0 / (e->planex * e->diry
		- e->dirx * e->planey);
	rs->tx = rs->invdet *
		(e->diry * rs->spritex - e->dirx * rs->spritey);
	rs->ty = rs->invdet * (-e->planey
		* rs->spritex + e->planex * rs->spritey);
	rs->spritescreenx = (int)((e->w / 2) * (1 + rs->tx / rs->ty));
	rs->spriteheight = abs((int)(e->h / rs->ty));
	rs->drawstarty = -rs->spriteheight / 2 + e->h / 2;
	if (rs->drawstarty < 0)
		rs->drawstarty = 0;
	rs->drawendy = rs->spriteheight / 2 + e->h / 2;
	if (rs->drawendy >= e->h)
		rs->drawendy = e->h - 1;
	rs->spritewidth = abs((int)(e->h / rs->ty));
	rs->drawstartx = -rs->spritewidth / 2 + rs->spritescreenx;
	if (rs->drawstartx < 0)
		rs->drawstartx = 0;
	rs->drawendx = rs->spritewidth / 2 + rs->spritescreenx;
	if (rs->drawendx >= e->w)
		rs->drawendx = e->w - 1;
	rs->stripe = rs->drawstartx;
}

void	draw_sprite(t_game *e, t_game *rc, t_raysprite *rs)
{
	while (rs->stripe < rs->drawendx)
	{
		rs->texx = (int)(256 * (rs->stripe - (-rs->spritewidth
			/ 2 + rs->spritescreenx)) * 64 / rs->spritewidth) / 256;
		if (rs->ty > 0 && rs->stripe > 0
				&& rs->stripe < e->w && rs->ty < rc->zbuffer[rs->stripe])
		{
			rs->y = rs->drawstarty;
			while (rs->y < rs->drawendy)
			{
				rs->d = (rs->y) * 256 - e->h * 128 + rs->spriteheight * 128;
				rs->texy = ((rs->d * 64) / rs->spriteheight) / 256;
				if (e->tex_arr[7].data[rs->texy % 64 *
					e->tex_arr[7].sizeline +
					rs->texx % 64 * e->tex_arr[7].bpp / 8] != 0)
					ft_memcpy(e->imgpoke + 4 * e->w * rs->y + rs->stripe * 4,
						&e->tex_arr[7].data[rs->texy % 64 *
						e->tex_arr[7].sizeline +
						rs->texx % 64 * e->tex_arr[7].bpp / 8],
						sizeof(int));
				rs->y++;
			}
		}
		rs->stripe++;
	}
}
