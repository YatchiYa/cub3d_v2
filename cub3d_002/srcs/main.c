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

int				main(int argc, char **argv)
{
	t_game	*g;
	int		screen;

	screen = 0;
	g = NULL;
	if (argc >= 2 && ft_strcmp(argv[1], "--save") == 0)
		screen = 1;
	if (argc < (2 + screen))
		exitit("Error:\nno map specified.\n", g);
	if (!(g = (t_game *)malloc(sizeof(t_game))))
		return (0);
	makewindow(g, screen, argv[1 + screen]);
	return (EXIT_SUCCESS);
}
