/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:32:01 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/02 15:25:11 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_endwith(char *str, char *end)
{
	int	length;
	int	end_length;

	length = ft_strlen(str);
	end_length = ft_strlen(end);
	if (end_length > length)
		return (0);
	while (end_length >= 0)
	{
		if (str[length] != end[end_length])
			return (0);
		end_length--;
		length--;
	}
	return (1);
}

void	check_texture_extension(t_game *g)
{
	if (g->no_texture && ft_endwith(g->no_texture, ".xpm") == 0)
		exitit_2("Error wall textures extension <.xpm>", g);
	if (g->so_texture && ft_endwith(g->so_texture, ".xpm") == 0)
		exitit_2("Error wall textures extension <.xpm>", g);
	if (g->we_texture && ft_endwith(g->we_texture, ".xpm") == 0)
		exitit_2("Error wall textures extension <.xpm>", g);
	if (g->ea_texture && ft_endwith(g->ea_texture, ".xpm") == 0)
		exitit_2("Error wall textures extension <.xpm>", g);
	if (g->s_texture && ft_endwith(g->s_texture, ".xpm") == 0)
		exitit_2("Error sprite textures extension <.xpm>", g);
}
