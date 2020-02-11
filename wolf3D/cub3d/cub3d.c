
#include "cub3d.h"

void	init_camera(t_game *game)
{
	game->camera.posx = 6;
	game->camera.posy = 8;
	game->camera.dirx = -1;
	game->camera.diry = 0;
	game->camera.planex = 0;
	game->camera.planey = 0.66;
}

void	init_config(t_game *game)
{
	game->conf.rotspeed = .5;
	game->conf.movespeed = .5;

	game->conf.upkey = 0;
	game->conf.downkey = 0;
	game->conf.leftkey = 0;
	game->conf.rightkey = 0;
}

void	init_raycast(t_game *game)
{
	game->raycast.time = 0;
	game->raycast.oldtime = 0;
}


void	initiodraw(t_game *game)
{
	init_camera(game);
	init_config(game);
	init_raycast(game);
	game->win.width = WIDTH;
	game->win.height = HEIGHT;
}


void	start_game(t_game *game)
{
	game->win.ptr_win = mlx_init();
	game->img.ptr_img = mlx_new_image(game->win.ptr_win, WIDTH, HEIGHT);
	game->win.win = mlx_new_window(game->win.ptr_win, WIDTH, HEIGHT, "Wolf3D");
	
	game->sky_floor[0].ptr_img = mlx_xpm_file_to_image(game->win.ptr_win, "./textures/clouds.xpm",
			&(game->sky_floor[0].w), &(game->sky_floor[0].h));
	game->sky_floor[0].img = (int*)mlx_get_data_addr(game->sky_floor[0].ptr_img, &(game->sky_floor[0].bpp),
			&(game->sky_floor[0].sl), &(game->sky_floor[0].end));


	game->sky_floor[1].ptr_img = mlx_xpm_file_to_image(game->win.ptr_win, "./textures/floor4",
			&(game->sky_floor[1].w), &(game->sky_floor[1].h));
	game->sky_floor[1].img = (int*)mlx_get_data_addr(game->sky_floor[1].ptr_img, &(game->sky_floor[1].bpp),
			&(game->sky_floor[1].sl), &(game->sky_floor[1].end));

	

	game->img.img = (int*)mlx_get_data_addr(game->img.ptr_img, &game->img.bpp, &(game->img.sl), &(game->img.end));
	
	initiodraw(game);
	drawstuff(game);



	mlx_put_image_to_window(game->win.ptr_win, game->win.win, game->sky_floor[0].ptr_img, 0, 0);
	mlx_put_image_to_window(game->win.ptr_win, game->win.win, game->sky_floor[1].ptr_img, 0, HEIGHT/2);
	mlx_put_image_to_window(game->win.ptr_win, game->win.win, game->img.ptr_img, 0, 0);
	mlx_loop(game->win.ptr_win);
}
