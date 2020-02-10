

# include "parse_map.h"

int
	count_check_columns(char const *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '1')
			j++;
		else if (line[i] != ' ')
			return (0);
		i++;
	}
	return (j);
}

int
	check_left_right_borders(t_str *map_buffer)
{
	int				i;
	int				first;
	int				last;

	if (!map_buffer)
		return (0);
	i = 0;
	while (map_buffer)
	{
		first = 0;
		while (map_buffer->content[first] == ' ')
			first++;
		last = ft_strlen(map_buffer->content) - 1;
		while (last > 0 && last == ' ')
			last--;
		if (last <= 1
			|| map_buffer->content[first] != '1'
			|| map_buffer->content[last] != '1')
			return (0);
		map_buffer = map_buffer->next;
		i++;
	}
	return (i);
}

int
	check_top_bottom_borders(t_str *map_buffer)
{
	int		first_line;
	int		last_line;
	t_str	*last;

	if (!map_buffer)
		return (0);
	first_line = count_check_columns(map_buffer->content);
	last = str_last(map_buffer);
	if (last)
		last_line = count_check_columns(last->content);
	else
		last_line = 0;
	if (first_line == last_line)
		return (first_line);
	return (0);
}

int
	check_valid(t_game_config *config, t_str *map_buffer)
{
	int	i;
	int	col;

	while (map_buffer)
	{
		i = 0;
		col = 0;
		while (map_buffer->content[i])
		{
			if (!ft_in_set(map_buffer->content[i], VALID_MAP_CHARACTERS))
				return (0);
			if (map_buffer->content[i++] != ' ')
				col++;
		}
		if (col != config->columns)
			return (0);
		map_buffer = (map_buffer)->next;
	}
	return (1);
}

int
	copy_map(t_game_config *config, t_str *map_buffer, int *map)
{
	int		i;
	int		j;
	int		line;
	int		has_camera;

	i = 0;
	has_camera = 0;
	while (map_buffer)
	{
		j = 0;
		line = 0;
		while (map_buffer->content[j])
		{
			while (map_buffer->content[j] == ' ')
				j++;
			map[(i * config->columns) + line++] = map_buffer->content[j];
			if (ft_in_set(map_buffer->content[j], DIRECTIONS))
				has_camera++;
			j++;
		}
		map_buffer = map_buffer->next;
		i++;
	}
	return (has_camera);
}

int ft_check_map(t_game_config *game_config, t_str *map_buffer)
{
    int *map;

    map = NULL;
    if ((game_config->columns = check_top_bottom_borders(map_buffer)) <= 2
        || (game_config->rows = check_left_right_borders(map_buffer)) <= 2
        || check_valid(game_config, map_buffer) == 0)
        return (0);
    if (!(map = (int*)malloc(sizeof(*map) * (game_config->columns * game_config->rows))))
        return(0);
	if (copy_map(game_config, map_buffer, map) != 1)
		return (0);
	game_config->maps = map;
	return (1);
}


int     parse_map(t_game_config *game_config, char *line, t_str **map_buffer, t_str *first_elem)
{
    int     i;
    int     j;
    char     *buffer;
    t_str   *new_str;

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
    new_str = str_add_back(map_buffer, ft_strdup(buffer));
    free(buffer);
    while (line[i] != '\0')
    {
        if (ft_isalphnum(line[i]) == 1)
            return (0);
        i++;
    }
    return(1);
}