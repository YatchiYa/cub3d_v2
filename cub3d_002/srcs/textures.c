
#include "wolf3d.h"
#include <math.h>


void    import_textures(t_game *g)
{
    int x = 64;
    g->tex_arr[0].img = mlx_xpm_file_to_image(g->mlx, "./xpm/wall.xpm", &x, &x);
	g->tex_arr[0].data = mlx_get_data_addr(g->tex_arr[0].img,
							&g->tex_arr[0].bpp,
							&g->tex_arr[0].sizeline,
							&g->tex_arr[0].endian);
}



void    draw_texture_wall(t_game *mlx, int x, int y)
{
    const void	*colour;
	int			ptr_color;
    import_textures(mlx);


	mlx->tex_hit_id = mlx->worldmap[mlx->mapx][mlx->mapy];
    
	if (mlx->side == 0)
		mlx->wall_at_ray_pos = mlx->rayposy + mlx->perpwalldist * mlx->raydiry;
	else
		mlx->wall_at_ray_pos = mlx->rayposx + mlx->perpwalldist * mlx->raydirx;
	mlx->tx_x = (int)(mlx->wall_at_ray_pos * (double)(64));
	if (mlx->side == 0 && mlx->raydirx > 0)
		mlx->tx_x = 64 - mlx->tx_x - 1;
	if (mlx->side == 1 && mlx->raydiry < 0)
		mlx->tx_x = 64 - mlx->tx_x - 1;
	// mlx->tx_x = fabs(mlx->tx_x);

    

	if (x < WIDTH && y < HEIGHT)
	{
		mlx->tx_y = abs((((y * 256 - HEIGHT * 128 +
								mlx->lineheight * 128) * 64) /
								mlx->lineheight) / 256);
		colour = &(mlx->tex_arr[0].data[(int)mlx->tx_y % 64 * mlx->tex_arr[0].sizeline 
        + (int)mlx->tx_x % 64 * mlx->tex_arr[0].bpp / 8]);
		ptr_color = *(int *)colour;
		if (mlx->side == 1)
			ptr_color = (ptr_color >> 1);
		mlx->imgpoke[mlx->mapy * mlx->sl + mlx->mapx * mlx->bpp / 8] = ptr_color;
		mlx->imgpoke[mlx->mapy * mlx->sl + mlx->mapx * mlx->bpp / 8 + 1] = ptr_color;
		mlx->imgpoke[mlx->mapy * mlx->sl + mlx->mapx * mlx->bpp / 8 + 2] = ptr_color;
	}
}