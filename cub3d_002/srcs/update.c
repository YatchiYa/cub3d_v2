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

void	redraw(t_game *g)
{
	mlx_destroy_image(g->mlx, g->img);
	g->img = mlx_new_image(g->mlx, g->w, g->h);
	g->imgpoke = mlx_get_data_addr(g->img, &g->bpp, &(g->sl), &(g->end));
	raycast_procjection(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	player(g);
}

void	makewindow(t_game *g, int screen, char *path)
{
	screen = 0;
	g->mlx = mlx_init();
	g->screen = screen;
	init_game(g);
	printf(" \n debug %s \n", path);
	if (parse_game_config(g, path) == 0)
		exitit("error while parsing the file", g);
	g->img = mlx_new_image(g->mlx, g->w, g->h);
	g->win = mlx_new_window(g->mlx, g->w, g->h, "cub3D");
	g->imgpoke = mlx_get_data_addr(g->img, &g->bpp, &(g->sl), &(g->end));
	raycast_procjection(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	player(g);
	mlx_loop_hook(g->mlx, repeat, g);
	mlx_loop(g->mlx);
}
