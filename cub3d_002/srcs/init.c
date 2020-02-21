#include "wolf3d.h"
#include <string.h>

void    import_textures(t_game *g)
{
    int x;
    int y;
    g->tex_arr[1].img = mlx_xpm_file_to_image(g->mlx, "xpm/redbrick.xpm", &x, &y);
	g->tex_arr[1].data = mlx_get_data_addr(g->tex_arr[1].img,
							&g->tex_arr[1].bpp,
							&g->tex_arr[1].sizeline,
							&g->tex_arr[1].endian);
    g->tex_arr[2].img = mlx_xpm_file_to_image(g->mlx, "xpm/grey.xpm", &x, &y);
	g->tex_arr[2].data = mlx_get_data_addr(g->tex_arr[2].img,
							&g->tex_arr[2].bpp,
							&g->tex_arr[2].sizeline,
							&g->tex_arr[2].endian);
    g->tex_arr[3].img = mlx_xpm_file_to_image(g->mlx, "xpm/mossy.xpm", &x, &y);
	g->tex_arr[3].data = mlx_get_data_addr(g->tex_arr[3].img,
							&g->tex_arr[3].bpp,
							&g->tex_arr[3].sizeline,
							&g->tex_arr[3].endian);
    g->tex_arr[4].img = mlx_xpm_file_to_image(g->mlx, "xpm/bluestone.xpm", &x, &y);
	g->tex_arr[4].data = mlx_get_data_addr(g->tex_arr[4].img,
							&g->tex_arr[4].bpp,
							&g->tex_arr[4].sizeline,
							&g->tex_arr[4].endian);

    g->tex_arr[5].img = mlx_xpm_file_to_image(g->mlx, "xpm/redbrick.xpm", &x, &y);
	g->tex_arr[5].data = mlx_get_data_addr(g->tex_arr[5].img,
							&g->tex_arr[5].bpp,
							&g->tex_arr[5].sizeline,
							&g->tex_arr[5].endian);


    g->tex_arr[6].img = mlx_xpm_file_to_image(g->mlx, "xpm/sand.xpm", &x, &y);
	g->tex_arr[6].data = mlx_get_data_addr(g->tex_arr[6].img,
							&g->tex_arr[6].bpp,
							&g->tex_arr[6].sizeline,
							&g->tex_arr[6].endian);
    g->tex_arr[7].img = mlx_xpm_file_to_image(g->mlx, "xpm/barrel.xpm", &x, &y);
	g->tex_arr[7].data = mlx_get_data_addr(g->tex_arr[7].img,
							&g->tex_arr[7].bpp,
							&g->tex_arr[7].sizeline,
							&g->tex_arr[7].endian);
    g->tex_arr[8].img = mlx_xpm_file_to_image(g->mlx, "xpm/pillar.xpm", &x, &y);
	g->tex_arr[8].data = mlx_get_data_addr(g->tex_arr[8].img,
							&g->tex_arr[8].bpp,
							&g->tex_arr[8].sizeline,
							&g->tex_arr[8].endian);
}

char	*replace(char *src, int start)
{
	int 	i;
	char	*dest;

	i = 0;
	if (!(dest = malloc(sizeof(char) * (strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		if (i == start)
			dest[i] = '0';
		else
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int			find_sprite(t_game *g)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while (i < 10)
	{
		j = 0;
		while (g->worldmap[i][j] != '\0')
		{
			if (g->worldmap[i][j] == '2' || g->worldmap[i][j] == '3')
			{
				g->sprite[nb] = g->worldmap[i][j] == '2' ?
					(t_sprite){i + 0.5, j + 0.5, 7} :
					(t_sprite){i + 0.5, j + 0.5, 8};
				g->worldmap[i] = replace(g->worldmap[i], j);
				nb++;
			}
			j++;
		}
		i++;
	}
	if (nb == 0)
		return (0);
	return (1);
}

void		set_direction(t_game *g, int direction)
{
	double	angle;

	if (direction == 83)
		angle = 135;
	else if (direction == 69)
		angle = 67.5;
	else if (direction == 87)
		angle = -67.5;
	else
		angle = 0;

	g->olddirx = g->dirx;
	g->dirx = g->dirx * cos(angle) - g->diry * sin(angle);
	g->diry = g->olddirx * sin(angle) +
	g->diry * cos(angle);
	g->oldplanex = g->planex;
	g->planex = g->planex * cos(angle) - g->planey * sin(angle);
	g->planey = g->oldplanex * sin(angle) +
	g->planey * cos(angle);
}

int		find_start_position(t_game *g)
{
	int	i;
	int	j;
	int	nb;
	int direction;

	i = 0;
	nb = 0;
	while (i < 10)
	{
		j = 0;
		while (g->worldmap[i][j] != '\0')
		{
			if (g->worldmap[i][j] == 'N' || g->worldmap[i][j] == 'S' || g->worldmap[i][j] == 'W' || g->worldmap[i][j] == 'E')
			{
				g->posx = i + 0.5;
				g->posy = j + 0.5;
				direction = (int)(g->worldmap[i][j]);
				g->worldmap[i] = replace(g->worldmap[i], j);
				nb++;
			}
			j++;
		}
		i++;
	}
	if (nb > 1 || nb == 0)
		return (0);
	return (direction);
}

void	init_game(t_game *g)
{
	int direction;

	g->dirx = -1;
	g->diry = 0;
	g->planex = 0;
	g->planey = 0.66;
	g->time = 0;
	g->oldtime = 0;
	g->w = WIDTH;
	g->h = HEIGHT;
	g->upkey = 0;
	g->downkey = 0;
	g->leftkey = 0;
	g->rightkey = 0;
	g->rk_move = 0;
	g->lf_move = 0;
	g->rotspeed = .07;
	g->movespeed = .11;
	g->x_text = 0;
	g->y_text = 0;
	g->texture = 0;
	g->speedup = 0;

	if (( direction = find_start_position(g)) != 0)
		set_direction(g, direction);
	else
		return ;
	if (find_sprite(g) == 0)
		return ;
    import_textures(g);
}

