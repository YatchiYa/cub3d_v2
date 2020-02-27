/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/02/27 15:19:01 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			find_sprite(t_game *g)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while (i < g->rows)
	{
		j = -1;
		while (++j < g->columns)
			if (g->wd[i][j] == 2 || g->wd[i][j] == 3)
			{
				g->sprite[nb] = g->wd[i][j] == 2 ?
					(t_sprite){i + 0.5, j + 0.5, 7} :
					(t_sprite){i + 0.5, j + 0.5, 8};
				g->wd[i][j] = 0;
				nb++;
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

	if (direction == 83 - 48)
		angle = 135;
	else if (direction == 69 - 48)
		angle = 67.5;
	else if (direction == 87 - 48)
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

int			find_start_position(t_game *g)
{
	int	i;
	int	j;
	int	nb;
	int direction;

	i = 0;
	nb = 0;
	while (i < g->rows)
	{
		j = -1;
		while (++j < g->columns)
			if (g->wd[i][j] == 78 - 48 || g->wd[i][j] == 83 - 48 ||
				g->wd[i][j] == 87 - 48 || g->wd[i][j] == 69 - 48)
			{
				g->posx = i + 0.5;
				g->posy = j + 0.5;
				direction = (int)(g->wd[i][j]);
				g->wd[i][j] = 0;
				nb++;
			}
		i++;
	}
	if (nb > 1 || nb == 0)
		return (0);
	return (direction);
}
