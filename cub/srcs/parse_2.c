/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/02/27 16:30:33 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		rgb_c(t_game *game_config, char **tab, int *result, char mode)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		result[i] = ft_atoi(tab[i]);
		if (result[i] > 255 || result[i] < 0)
		{
			i = 0;
			while (tab[i])
			{
				free(tab[i]);
				i++;
			}
			free(tab);
			free(result);
			return (0);
		}
		i++;
	}
	tx(game_config, result, mode, tab);
	return (1);
}

void	parse_width(t_game *game_config, char *used)
{
	int width;

	width = ft_atoi(used);
	if (width > 1980)
		game_config->w = 1980;
	else if (width < game_config->w)
		;
	else
		game_config->w = width;
}

void	parse_height(t_game *game_config, char *used)
{
	int height;

	height = ft_atoi(used);
	if (height > 1400)
		game_config->h = 1400;
	else if (height < game_config->h)
		;
	else
		game_config->h = height;
}

void	bb(char *line, int i, t_game *game_config)
{
	int		j;
	char	*used;

	used = (char*)malloc(sizeof(char) * 6);
	i = 0;
	j = 0;
	while (ft_isnum(line[i]) == 0 || line[i] == ' ')
		i++;
	while (ft_isnum(line[i]))
	{
		used[j] = line[i];
		i++;
		j++;
	}
	used[j] = '\0';
	parse_height(game_config, used);
	free(used);
}

int		parse_resolution(t_game *game_config, char *line)
{
	int		i;
	int		j;
	char	*used;

	i = 0;
	j = 0;
	if (!(used = (char*)malloc(sizeof(char) * 6)))
		return (0);
	while (line[i] == 'R' || line[i] == ' ')
		i++;
	if (ft_isnum(line[i]) == 0)
		return (0);
	while (ft_isnum(line[i]) && line[i] != ' ')
	{
		used[j] = line[i];
		i++;
		j++;
	}
	used[j] = '\0';
	parse_width(game_config, used);
	free(used);
	bb(&line[i], i, game_config);
	game_config->r_resolution = line;
	return (1);
}
