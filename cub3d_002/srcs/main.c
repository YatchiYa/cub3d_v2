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

void			map(t_game *g)
{
	g->worldmap[0] = "1111111111";
	g->worldmap[1] = "100E000201";
	g->worldmap[2] = "1000000001";
	g->worldmap[3] = "1100020001";
	g->worldmap[4] = "1000110001";
	g->worldmap[5] = "1000011001";
	g->worldmap[6] = "1001001001";
	g->worldmap[7] = "1101111001";
	g->worldmap[8] = "1000000001";
	g->worldmap[9] = "1111111111";
}

int				close_win(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	free(g);
	exitit("Exiting");
	return (0);
}

int				main(int argc, char **argv)
{
	t_game	*g;
	int		screen;

	screen = 0;
	if (argc >= 2 && ft_strcmp(argv[1], "--save") == 0)
        screen = 1;
	if (argc < (2 + screen))
		exitit("Error:\nno map specified.\n");
	if (!argc && !argv)
		return (0);
	if (!(g = (t_game *)malloc(sizeof(t_game))))
		return (0);
	map(g);
	init_game(g);
	makewindow(g);
}
