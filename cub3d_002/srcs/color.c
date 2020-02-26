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
