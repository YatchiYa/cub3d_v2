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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dst2;
	size_t			i;

	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}

int	wall_direction(t_game *ray)
{
	if (ray->side)
		return ((ray->raydiry < 0) ? WALL_N : WALL_S );
	return ((ray->raydirx < 0) ? WALL_W : WALL_E);
}

int	wall_tex(t_game *ray)
{
	if (ray->side)
		return ((ray->raydiry < 0) ? 1 : 2);
	return ((ray->raydirx < 0) ? 3 : 4);
}

void	put_pxl_to_img(t_game *t, int x, int y, int color)
{
	if (t->texture == 1 && x < WIDTH && y < HEIGHT)
	{
		int id = wall_tex(t);
		t->y_text = abs((((y * 256 - HEIGHT * 128 + t->lineheight * 128) * 64)
					/ t->lineheight) / 256);
		ft_memcpy(t->imgpoke + 4 * WIDTH * y + x * 4,
			&t->tex_arr[id].data[t->y_text % 64 * t->tex_arr[id].sizeline +
			t->x_text % 64 * t->tex_arr[id].bpp / 8], sizeof(int));
	}
	else if (x < WIDTH && y < HEIGHT)
		ft_memcpy(t->imgpoke + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
}

void			draw_sky_floor(int x, t_game *t)
{
	if (t->texture == 0)
	{
		// draw sky
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
		if (t->drawend > 0)		// draw floor
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

// return ((ray->raydiry < 0) ? (TEX_NORTH) : (TEX_SOUTH));
// 	return ((ray->raydirx < 0) ? (TEX_WEST) : (TEX_EAST));


void	draw_wallxx(int x, int start, int end, t_game *t)
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
		// g->imgpoke[x + (start * g->sl / 4)] = wall_direction(g);
}

void	draw_sky(t_game *t)
{
	t->x_text = 0;
	while (t->x_text < WIDTH)
	{
		t->y_text = 0;
		while (t->y_text < HEIGHT / 2)
		{
			ft_memcpy(t->imgpoke + 4 * WIDTH * t->y_text + t->x_text * 4,
					&t->tex_arr[5].data[t->y_text % 512 * t->tex_arr[5].sizeline +
					t->x_text % 512 * t->tex_arr[5].bpp / 8], sizeof(int));
			t->y_text++;
		}
		t->x_text++;
	}
}

void	draw_floor(t_game *t)
{
	t->x_text = 0;
	while (t->x_text < WIDTH)
	{
		t->y_text = HEIGHT / 2;
		while (t->y_text < HEIGHT)
		{
			ft_memcpy(t->imgpoke + 4 * WIDTH * t->y_text + t->x_text * 4,
					&t->tex_arr[6].data[t->y_text % 64 * t->tex_arr[6].sizeline +
					t->x_text % 64 * t->tex_arr[6].bpp / 8], sizeof(int));
			t->y_text++;
		}
		t->x_text++;
	}
}


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
		if (g->worldmap[g->mapx][g->mapy] != '0')
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



	// wall_color(g);
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
	g->x = -1;
	if (g->texture == 1)
	{
		draw_sky(g);
		draw_floor(g);
	}
	while (++g->x < g->w)
	{
		raycast_init(g);
		raycast_dist(g);
		raycat_object(g);
		raycast_draw(g);
		g->zbuffer[g->x] = g->perpwalldist;
	}

	t_raysprite	rs;
	
	rs.i = 0;
	while (rs.i < 3)
	{
		ray_sprite(g, &rs);
		draw_sprite(g, g, &rs);
		rs.i++;
	}
}
