
# include "config_parse.h"

int parse_resolution(t_game_config *game_config, char *line)
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
    if(ft_atoi(used) > game_config->width)
        game_config->width = ft_atoi(used);
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
    if(ft_atoi(used) > game_config->height)
        game_config->height = ft_atoi(used);
    free(used);
    while (line[i] != '\0')
    {
        if (ft_isalphnum(line[i]) == 1)
            return (0);
        i++;
    }
    return(1);
}

int parse_NOSOWEEA(t_game_config *game_config, char *line, char *mode)
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
    while (line[i] != '\0')
    {
        if (ft_isalphnum(line[i]) == 1)
            return (0);
        i++;
    }
    return(1);
}

int fill_rgb_color(t_game_config *game_config, char *str, char mode)
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
    return (1); 
}

int parse_FC_color(t_game_config *game_config, char *line, char mode)
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
    while (line[i] != '\0')
    {
        if (ft_isalphnum(line[i]) == 1)
            return (0);
        i++;
    }
    return(1);
}
