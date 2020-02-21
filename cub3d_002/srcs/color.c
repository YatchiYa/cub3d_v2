
#include "wolf3d.h"

unsigned int	pick_color(int i, double x, double y)
{
	unsigned int	color;
	double			color_2;
	double			i2;
	t_game			g;

	color_2 = sqrt(x * x + y * y);
	i2 = i + 1 - (log(2) / color_2) / log(2);
	g.chan[0] = (unsigned char)(sin(0.026 * i2 + 4) * 230 + 25);
	g.chan[1] = (unsigned char)(sin(0.023 * i2 + 2) * 230 + 25);
	g.chan[2] = (unsigned char)(sin(0.01 * i2 + 1) * 230 + 25);
	color = (g.chan[0] << 16) + (g.chan[1] << 8) + (g.chan[2] + 255);
	return (color);
}
