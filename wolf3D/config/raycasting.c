
#include "config_all.h"

void			verLine(t_game *game, int x)
{
	int		start_pos;
	int		end_pos;
	int		i;

	end_pos = game->draw.drawend;
	if (end_pos > HEIGHT)
		end_pos = HEIGHT - 1;
	start_pos = game->draw.drawstart;
	if (start_pos < 0)
		start_pos = 0;
	i = -1;
	while (++i < (HEIGHT / 2))
		game->img.img[x + (i * game->img.sl / 4)] = 0xC00000AA;
	while (++start_pos < end_pos)
		game->img.img[x + (start_pos * game->img.sl / 4)] = colormagic(game->color.color, x, start_pos);
	i = end_pos - 1;
	while (++i < (HEIGHT - 1))
		game->img.img[x + (i * game->img.sl / 4)] = 0xC00000AA;
}

void	raycast1(t_game *game)
{
	game->camera.camerax = 2 * game->win.x / (double)game->win.width - 1;
	game->raycast.rayposx = game->camera.posx;
	game->raycast.rayposy = game->camera.posy;
	game->raycast.raydirx = game->camera.dirx + game->camera.planex * game->camera.camerax;
	game->raycast.raydiry = game->camera.diry + game->camera.planey * game->camera.camerax;
	game->raycast.mapx = (int)game->raycast.rayposx;
	game->raycast.mapy = (int)game->raycast.rayposy;
	game->raycast.deltadistx = sqrt(1 + (game->raycast.raydiry *
				game->raycast.raydiry) / (game->raycast.raydirx * game->raycast.raydirx));
	game->raycast.deltadisty = sqrt(1 + (game->raycast.raydirx *
				game->raycast.raydirx) / (game->raycast.raydiry * game->raycast.raydiry));
	game->raycast.hit = 0;
}

void	raycast2(t_game *game)
{
	if (game->raycast.raydirx < 0)
	{
		game->raycast.stepx = -1;
		game->raycast.sidedistx = (game->raycast.rayposx - game->raycast.mapx) * game->raycast.deltadistx;
	}
	else
	{
		game->raycast.stepx = 1;
		game->raycast.sidedistx = (game->raycast.mapx + 1.0 - game->raycast.rayposx) * game->raycast.deltadistx;
	}
	if (game->raycast.raydiry < 0)
	{
		game->raycast.stepy = -1;
		game->raycast.sidedisty = (game->raycast.rayposy - game->raycast.mapy) * game->raycast.deltadisty;
	}
	else
	{
		game->raycast.stepy = 1;
		game->raycast.sidedisty = (game->raycast.mapy + 1.0 - game->raycast.rayposy) * game->raycast.deltadisty;
	}
}

void	raycast3(t_game *game)
{
	while (game->raycast.hit == 0)
	{
		if (game->raycast.sidedistx < game->raycast.sidedisty)
		{
			game->raycast.sidedistx += game->raycast.deltadistx;
			game->raycast.mapx += game->raycast.stepx;
			game->raycast.side = 0;
		}
		else
		{
			game->raycast.sidedisty += game->raycast.deltadisty;
			game->raycast.mapy += game->raycast.stepy;
			game->raycast.side = 1;
		}
		if (game->conf.worldmap[game->raycast.mapx][game->raycast.mapy] != '0')
			game->raycast.hit = 1;
	}
	if (game->raycast.side == 0)
		game->raycast.perpwalldist = (game->raycast.mapx - game->raycast.rayposx +
				(1 - game->raycast.stepx) / 2) / game->raycast.raydirx;
	else
		game->raycast.perpwalldist = (game->raycast.mapy - game->raycast.rayposy +
				(1 - game->raycast.stepy) / 2) / game->raycast.raydiry;
	game->draw.lineheight = (int)(game->win.height / game->raycast.perpwalldist);
	game->draw.drawstart = -(game->draw.lineheight) / 2 + game->win.height / 2;
}

void	raycast4(t_game *game)
{
	game->draw.drawstart = -(game->draw.lineheight) / 2 + game->win.height / 2;
	if (game->draw.drawstart < 0)
		game->draw.drawstart = 0;
	game->draw.drawend = game->draw.lineheight / 2 + game->win.height / 2;
	if (game->draw.drawend >= game->win.height)
		game->draw.drawend = game->win.height - 1;
	wall_color(game);
	if (game->raycast.side == 1)
		game->color.color = game->color.color / 2;
	verLine(game, game->win.x);
}

void	drawstuff(t_game *game)
{
	game->win.x = -1;
	while (++game->win.x < game->win.width)
	{
		raycast1(game);
		raycast2(game);
		raycast3(game);
		raycast4(game);
	}
}
