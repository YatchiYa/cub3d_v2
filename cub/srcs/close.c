/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/03/06 19:23:51 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				close_win(t_game *g)
{
	exitit("Exiting", g);
	return (0);
}

void			ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void			exitit(char *str, t_game *g)
{
	if (g)
		;
	ft_putstr(str);
	free(g->zbuffer);
	exit(1);
}

void			exitit_2(char *str, t_game *g)
{
	if (g)
		;
	ft_putstr(str);
	exit(1);
}
