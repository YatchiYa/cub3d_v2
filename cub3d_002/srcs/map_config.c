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

int			ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*replace(char *src, int start)
{
	int			i;
	char		*dest;

	i = 0;
	if (!(dest = malloc(sizeof(char) * (ft_strlen(src) + 1))))
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



char		*replacex(char *src, int start)
{
	int			i;
	char		*dest;

	i = 0;
	if (!(dest = malloc(sizeof(char) * (ft_strlen(src) + 1))))
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

int			find_start_position(t_game *g)
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
			if (g->worldmap[i][j] == 'N' || g->worldmap[i][j] == 'S' ||
				g->worldmap[i][j] == 'W' || g->worldmap[i][j] == 'E')
			{
				g->posx = i + 0.5;
				g->posy = j + 0.5;
				direction = (int)(g->worldmap[i][j]);
				g->worldmap[i] = replacex(g->worldmap[i], j);
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
