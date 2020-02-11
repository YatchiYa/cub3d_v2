
#include "config_all.h"

unsigned int	colormagic(int i, double x, double y)
{
	unsigned int	color;
	double			magic;
	double			i2;
	t_game			g;

	magic = sqrt(x * x + y * y);
	i2 = i + 1 - (log(2) / magic) / log(2);
	g.chan[0] = (unsigned char)(sin(0.026 * i2 + 4) * 230 + 25);
	g.chan[1] = (unsigned char)(sin(0.023 * i2 + 2) * 230 + 25);
	g.chan[2] = (unsigned char)(sin(0.01 * i2 + 1) * 230 + 25);
	color = (g.chan[0] << 16) + (g.chan[1] << 8) + (g.chan[2] + 255);
	return (color);
}

void	wall_color(t_game *game)
{
	char initio;

	initio = game->conf.worldmap[game->raycast.mapx][game->raycast.mapy];
	if (initio == '1')
		game->color.color = 0x00FFFF;
	else if (initio == '2')
		game->color.color = 0x0000FF;
	else if (initio == '3')
		game->color.color = 0x9400D3;
	else if (initio == '4')
		game->color.color = 0xFF8C00;
	else if (initio == '0')
		game->color.color = 0x008080;
}
