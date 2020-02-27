/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/02/27 16:40:35 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	redraw(t_game *g)
{
	mlx_destroy_image(g->mlx, g->img);
	g->img = mlx_new_image(g->mlx, g->w, g->h);
	g->imgpoke = mlx_get_data_addr(g->img, &g->bpp, &(g->sl), &(g->end));
	raycast_procjection(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	player(g);
}

void	pp(t_game *game, char *line, t_str *map_buffer, int fd)
{
	game->columns = ft_strlen(line);
	game->rows = str_length(map_buffer);
	if (ft_check_map(game, map_buffer) == 0)
		exitit(" error map format ", game);
	free(line);
	close(fd);
	str_clear(&map_buffer);
}

int		pg(t_game *game, char *path)
{
	int			fd;
	t_str		*map_buffer;
	char		*line;
	int			ret;

	map_buffer = NULL;
	if (ft_endwith(path, ".cub") == 0)
		exitit(" not valid map :  please specify --save and .cub", game);
	if ((fd = open(path, O_RDONLY)) < 0)
		exitit(" can't open the file ", game);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ft_parse_line(game, line, &map_buffer) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (ret == 0 && ft_strlen(line) > 0)
		str_add_back(&map_buffer, ft_strdup(line));
	pp(game, line, map_buffer, fd);
	return (1);
}

void	makewindow(t_game *g, int screen, char *path)
{
	g->mlx = mlx_init();
	init_game(g);
	if (pg(g, path) == 0)
		exitit("error while parsing the file", g);
	init_game_2(g);
	g->img = mlx_new_image(g->mlx, g->w, g->h);
	g->win = mlx_new_window(g->mlx, g->w, g->h, "cub3D");
	g->imgpoke = mlx_get_data_addr(g->img, &g->bpp, &(g->sl), &(g->end));
	raycast_procjection(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	player(g);
	if (screen == 1)
		ft_bitmap(g);
	mlx_loop_hook(g->mlx, repeat, g);
	mlx_loop(g->mlx);
}
