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
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->imgpoke = mlx_get_data_addr(g->img, &g->bpp, &(g->sl), &(g->end));
	raycast_procjection(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	player(g);
}

void	makewindow(t_game *g)
{
	g->mlx = mlx_init();
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "cub3D");
	g->imgpoke = mlx_get_data_addr(g->img, &g->bpp, &(g->sl), &(g->end));
	init_game(g);
	raycast_procjection(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	player(g);
	mlx_loop_hook(g->mlx, repeat, g);
	mlx_loop(g->mlx);
}
