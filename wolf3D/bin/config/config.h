
#ifndef CONFIG_H
# define CONFIG_H


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>


// to replace zith the parsed data from the file 

# define MAPH 10
# define MAPW 10
# define HEIGHT 500
# define WIDTH 1200

# define SKY 0
# define FLOOR 1

typedef struct s_config
{
    char    *worldmap[MAPH];
	double			movespeed;
	double			rotspeed;
	int				upkey;
	int				downkey;
	int				leftkey;
	int				rightkey;

}              t_config;

typedef struct s_window
{
    void    		*ptr_win;
    void   			*win;
	int				x;
	int				y;
	int				width;
	int				d;
	int				height;
}              t_window;

typedef struct  s_img
{
    void    *ptr_img;
    int    	*img;
	int		bpp;
	int		sl;
	int		end;
	int		h;
	int		w;

}              t_img;

typedef	struct	s_camera
{
	double			camerax;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	// double			oldplanex;
	// double			olddirx;

}				t_camera;


typedef	struct	s_raycast
{
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			time;
	double			oldtime;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				mapx;
	int				mapy;

}				t_raycast;

typedef	struct	s_draw
{
	int				lineheight;
	int				drawstart;
	int				drawend;
}				t_draw;

typedef	struct	s_color
{
	int				color;
	int				ycolor;
	int				xcolor;
}				t_color;

typedef struct		s_game
{
	t_config		conf;
	t_window		win;
	t_img			img;
	t_camera		camera;
	t_raycast		raycast;
	t_draw			draw;
	t_color			color;
	t_img			sky_floor[2];

	unsigned char	chan[3];
}					t_game;


void	start_game(t_game *g);

#endif