/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/02/27 16:47:51 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_fill_tab(int *tab, t_str *map_buffer)
{
	int i;

	i = 0;
	while (map_buffer->content[i] != '\0')
	{
		tab[i] = map_buffer->content[i] - 48;
		i++;
	}
}

void			tx(t_game *game_config, int *result, char mode, char **tab)
{
	int	i;

	i = 0;
	if (mode == 'F')
		game_config->f_color = result;
	else if (mode == 'C')
		game_config->c_color = result;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int				wall_direction(t_game *ray)
{
	if (ray->side)
		return ((ray->raydiry < 0) ? WALL_N : WALL_S);
	return ((ray->raydirx < 0) ? WALL_W : WALL_E);
}

int				wall_tex(t_game *ray)
{
	if (ray->side)
		return ((ray->raydiry < 0) ? 1 : 2);
	return ((ray->raydirx < 0) ? 3 : 4);
}
