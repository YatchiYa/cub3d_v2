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

void	put_pxl_to_img(t_game *t, int x, int y, int color)
{
	int	id;

	if (t->texture == 1 && x < t->w && y < t->h)
	{
		id = wall_tex(t);
		t->y_text = abs((((y * 256 - t->h * 128 + t->lineheight * 128) * 64)
					/ t->lineheight) / 256);
		ft_memcpy(t->imgpoke + 4 * t->w * y + x * 4,
			&t->tex_arr[id].data[t->y_text % 64 * t->tex_arr[id].sizeline +
			t->x_text % 64 * t->tex_arr[id].bpp / 8], sizeof(int));
	}
	else if (x < t->w && y < t->h)
		ft_memcpy(t->imgpoke + 4 * t->w * y + x * 4,
				&color, sizeof(int));
}
