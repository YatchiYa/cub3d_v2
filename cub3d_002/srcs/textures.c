
#include "wolf3d.h"
#include <math.h>

// void    draw_texture_wall(int x, t_game *t)
// {
// 	int		start;
// 	int		end;

// 	end = t->drawend;
// 	if (end > HEIGHT)
// 		end = HEIGHT - 1;
// 	start = t->drawstart;
// 	if (start < 0)
// 		start = 0;

// 		t->id = t->worldmap[t->mapx][t->mapy];
// 		if (t->side == 0)
// 			t->x_wall = t->rayposy + t->perpwalldist * t->raydiry;
// 		else
// 			t->x_wall = t->rayposx + t->perpwalldist * t->raydirx;
// 		t->x_text = (int)(t->x_wall * (double)(64));
// 		if (t->side == 0 && t->raydirx > 0)
// 			t->x_text = 64 - t->x_text - 1;
// 		if (t->side == 1 && t->raydiry < 0)
// 			t->x_text = 64 - t->x_text - 1;
// 		t->x_text = abs(t->x_text);

// 	// while (++start <= end)
// 	// 	put_pxl_to_img(t, x, start, t->color);

// }
