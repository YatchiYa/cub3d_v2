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

int parse_resolution(t_game *game_config, char *line)
{
    int i;
    int j;
    char    *used;
    
    i = 0;
    j = 0;
    used = (char*)malloc(sizeof(char) * 6);
    // for width
    while (line[i] == 'R' || line[i] == ' ')
        i++;
    if (ft_isnum(line[i]) == 0)
        return (0);
    while (ft_isnum(line[i]))
    {
        used[j] = line[i];
        i++;
        j++;
    }
    used[j] = '\0';
    if(ft_atoi(used) > game_config->w)
        game_config->w = ft_atoi(used);
    free(used);
    used = (char*)malloc(sizeof(char) * 6);
    j = 0;
    // for height
    while (ft_isnum(line[i]) == 0)
        i++;
    while (ft_isnum(line[i]))
    {
        used[j] = line[i];
        i++;
        j++;
    }
    used[j] = '\0';
    if(ft_atoi(used) > game_config->h)
        game_config->h = ft_atoi(used);
    free(used);
    return(1);
}

int parse_NOSOWEEA(t_game *game_config, char *line, char *mode)
{
    int i;
    int j;
    char    *used;
    
    i = 0;
    j = 0;
    used = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1));
    while(line[i] == ' ')
        i++;
    while (line[i] && line[i] != ' ')
    {
        used[j] = line[i];
        i++;
        j++;
    }
    used[j] = '\0';
    if (ft_strcmp(mode, "NO") == 0)
        game_config->NO_texture = ft_strdup(used);
    else if (ft_strcmp(mode, "SO") == 0)
        game_config->SO_texture = ft_strdup(used);
    else if (ft_strcmp(mode, "WE") == 0)
        game_config->WE_texture = ft_strdup(used);
    else if (ft_strcmp(mode, "EA") == 0)
        game_config->EA_texture = ft_strdup(used);
    else if (ft_strcmp(mode, "ST") == 0)
        game_config->ST_texture = ft_strdup(used);
    else if (ft_strcmp(mode, "FT") == 0)
        game_config->FT_texture = ft_strdup(used);
    else if (ft_strcmp(mode, "S") == 0)
        game_config->S_texture = ft_strdup(used);
    free(used);
    return(1);
}

int fill_rgb_color(t_game *game_config, char *str, char mode)
{
    int     i;
    char    **tab;
    int     *result;

    i = 0;
    result = (int*)malloc(sizeof(int) * 3);
    while (str[i])
    {
        if (ft_isnum(str[i]) == 1 || str[i] == ',')
            i++;
        else
            return (0);
    }
    i = 0;
    tab = ft_split(str, ',');
    while (tab[i])
    {
        result[i] = ft_atoi(tab[i]);
        if (result[i] > 255 || result[i] < 0)
            return (0);
        i++;
    }
    if (mode == 'F')
        game_config->F_color = result;
    else if (mode == 'C')
        game_config->C_color = result;
    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(result);
    return (1); 
}

int parse_FC_color(t_game *game_config, char *line, char mode)
{
    int i;
    int j;
    char    *used;

    i = 0;
    j = 0;
    used = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1));
    while(line[i] == ' ')
        i++;
    if (ft_isnum(line[i]) == 0)
        return (0);
    while (line[i] && line[i] != ' ')
    {
        used[j] = line[i];
        j++;
        i++;
    }
    used[j] = '\0';
    if (fill_rgb_color(game_config, used, mode) == 0)
        return (0);
    free(used);
    return(1);
}

int     parse_map(char *line, t_str **map_buffer)
{
    int     i;
    int     j;
    char     *buffer;

    i = 0;
    j = 0;
    buffer = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1));
    while (line[i] && line[i] != ' ')
    {
        buffer[j] = line[i];
        i++;
        j++;
    }
    buffer[j] = '\0';
    str_add_back(map_buffer, ft_strdup(buffer));
    free(buffer);
    return(1);
}
