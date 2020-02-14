#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../minilibx/mlx.h"

# define HEIGHT 840
# define WIDTH 1280
# define MAPH 10
# define MAPW 10
# define WALL_T 0x0D3558
# define WALL_B 0x0B2D4B
# define WALL_N 0x174F80
# define WALL_E 0x1B5C96
# define WALL_S 0x14446e
# define WALL_W 0x804d17


typedef struct	s_image
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_image;



typedef struct		s_game
{
	t_image		tex_arr[9];

	void			*wall_tex;
	int				tex_hit_id;
	
	int				*data_wall_tex;
	int				wall_tex_height;
	int				wall_tex_width;
	int				sl_s;
	int				end_s;
	int				bpp_s;

	int				tx_x;
	int				tx_y;




	char			*worldmap[MAPH];
	void			*mlx;
	void			*win;
	void			*img;

	void			*healthbar;
	int				*imgpoke;


	int				*imghealth;

	int				sl;
	int				end;
	int				bpp;

	int				health_w;
	int				health_h;
	int				health_bpp;
	int				health_sl;
	int				health_end;

	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				wall_at_ray_pos;
	
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				x;
	int				y;
	int				w;
	int				d;
	int				h;
	
	int				color;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				ycolor;
	int				xcolor;
	double			movespeed;
	double			rotspeed;
	double			oldplanex;
	double			olddirx;


	int				upkey;
	int				downkey;
	int				leftkey;
	int				rightkey;
	int				rk_move;
	int				lf_move;
	unsigned char	chan[3];
}					t_game;

void				map(t_game *g);
void				exitit(char	*str);
int					close_win(t_game *g);
unsigned int	pick_color(int i, double x, double y);
void			draw_wall(t_game *g, int x);
void				player(t_game *g);
void				wall_color(t_game *g);
void				init_game(t_game *g);
void				raycast_procjection(t_game *g);
void				printcontrols(int i);
void				errorcheck(char *str);
void				upmove(t_game *g);
void				downmove(t_game *g);
void				rightmove(t_game *g);
void				leftmove(t_game *g);
void				right_move(t_game *g);
void				left_move(t_game *g);
int					keyhooks(int key, t_game *g);
int					key_press(int key, t_game *g);
int					key_release(int key, t_game *g);
void				makewindow(t_game *g);
void				redraw(t_game *g);
int					repeat(t_game *g);
void				draw_background(t_game *g, int x);
void    draw_texture_wall(t_game *mlx, int x, int y);

#endif
