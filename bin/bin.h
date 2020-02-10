
#ifndef BIN_H
# define BIN_H


typedef	struct	s_game_config
{
    int     height;
    int     width;
    int     columns;
    int     rows;
    int     *maps;
    char    *NO_texture;
    char    *SO_texture;
    char    *WE_texture;
    char    *EA_texture;
    char    *ST_texture;
    char    *FT_texture;
    char    *S_texture;
    int     *F_color;
    int     *C_color;

}				t_game_config;

typedef	struct	s_game
{
    t_game_config   game_config;
    int screen_flag;

}				t_game;



#endif
