/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by yarab             #+#    #+#             */
/*   Updated: 2020/03/02 16:37:50 by yarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	tt(char *mode, t_game *game_config, char *used)
{
	if (ft_strcmp(mode, "NO") == 0)
		game_config->no_texture = ft_strdup(used);
	else if (ft_strcmp(mode, "SO") == 0)
		game_config->so_texture = ft_strdup(used);
	else if (ft_strcmp(mode, "WE") == 0)
		game_config->we_texture = ft_strdup(used);
	else if (ft_strcmp(mode, "EA") == 0)
		game_config->ea_texture = ft_strdup(used);
	else if (ft_strcmp(mode, "ST") == 0)
		game_config->st_texture = ft_strdup(used);
	else if (ft_strcmp(mode, "FT") == 0)
		game_config->ft_texture = ft_strdup(used);
	else if (ft_strcmp(mode, "S") == 0)
		game_config->s_texture = ft_strdup(used);
}

int		parse_nosoweea(t_game *game_config, char *line, char *mode)
{
	int		i;
	int		j;
	char	*used;

	i = 0;
	j = 0;
	used = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ')
	{
		used[j] = line[i];
		i++;
		j++;
	}
	used[j] = '\0';
	tt(mode, game_config, used);
	free(used);
	return (1);
}

int		fill_rgb_color(t_game *game_config, char *str, char mode)
{
	int		i;
	char	**tab;
	int		*result;

	i = 0;
	if (!(result = (int*)malloc(sizeof(int) * 3)))
		return (0);
	while (str[i])
	{
		if (ft_isnum(str[i]) == 1 || str[i] == ',')
			i++;
		else
			return (0);
	}
	i = 0;
	tab = ft_split(str, ',');
	if (rgb_c(game_config, tab, result, mode) == 0)
		return (0);
	return (1);
}

int		parse_fc_color(t_game *game_config, char *line, char mode)
{
	int		i;
	int		j;
	char	*used;

	i = 0;
	j = 0;
	used = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[i] == ' ')
		i++;
	if (ft_isnum(line[i]) == 0)
		return (0);
	while (line[i])
	{
		used[j] = line[i];
		j++;
		i++;
	}
	used[j] = '\0';
	if (fill_rgb_color(game_config, used, mode) == 0)
	{
		free(used);
		return (0);
	}
	free(used);
	return (1);
}

int		parse_map(char *line, t_str **map_buffer)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	if (!(buffer = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1))))
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] != '\0')
		{
			buffer[j] = line[i];
			j++;
		}
		i++;
	}
	buffer[j] = '\0';
	str_add_back(map_buffer, ft_strdup(buffer));
	free(buffer);
	return (1);
}
