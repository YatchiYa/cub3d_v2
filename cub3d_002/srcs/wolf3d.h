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
# define texWidth 64
# define texHeight 64
# define WALL_T 0x0D3558
# define WALL_B 0x0B2D4B
# define WALL_N 0x174F80
# define WALL_E 0x1B5C96
# define WALL_S 0x14446e
# define WALL_W 0x804d17

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

typedef struct	s_image
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_image;


typedef struct	sprite
{
	double x;
	double y;
	double d;
}				t_sprite;

typedef struct		s_game
{
	t_image		tex_arr[9];
	t_sprite	sprite;

	void			*wall_tex;
	int				tex_hit_id;
	
	int				*data_wall_tex;
	int				wall_tex_height;
	int				wall_tex_width;
	int				sl_s;
	int				end_s;
	int				bpp_s;

	int				id;
	int				texture;
	int				x_text;
	int				y_text;
	double			x_wall;




	char			*worldmap[MAPH];
	void			*mlx;
	void			*win;
	void			*img;

	void			*healthbar;
	void			*imgpoke;


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
	double			dira;
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
	int				speedup;


	int				upkey;
	int				downkey;
	int				leftkey;
	int				rightkey;
	int				rk_move;
	int				lf_move;
	unsigned char	chan[3];


	double			rayDirX0;
	double			rayDirY0;
	double			rayDirX1;
	double			rayDirY1;
	int				p;
	double			posZ;
	double			rowDistance;
	double			floorStepX;
	double			floorStepY;
	double			floorX;
	double			floorY;
	int				cellX;
	int				cellY;
	int				tx;
	int				ty;
	double			floorXWall;
	double			floorYWall;
	double			distWall;
	double			distPlayer;
	double			currentDist;
	double			weight;
	double			currentFloorX;
	double			currentFloorY;
	int			floorTexX;
	int			floorTexY;
	double		ZBuffer[WIDTH];

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
void    draw_texture_wall(int x, t_game *t);
void    import_textures(t_game *g);
int	wall_direction(t_game *ray);
void	put_pxl_to_img(t_game *t, int x, int y, int color);
void        floor_cast(t_game *g);
void        sky_cast(t_game *g);
void      sprite_cast(t_game *g);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
