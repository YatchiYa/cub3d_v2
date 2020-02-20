
#include "wolf3d.h"
#include <math.h>
#include <string.h>

// void	raycast_sky(t_game *g)
// {
// 	g->y = HEIGHT / 2;
// 	while (++g->y < HEIGHT)
// 	{
// 		g->rayDirX0 = g->raydirx - g->planex;
//       	g->rayDirY0 = g->raydiry - g->planey;
//       	g->rayDirX1 = g->raydirx + g->planex;
//       	g->rayDirY1 = g->raydiry + g->planey;
// 		g->p = g->y - HEIGHT / 2;
// 		g->posZ = 0.5 * HEIGHT;
// 		g->rowDistance = g->posZ / g->p;
// 		g->floorStepX = g->rowDistance * (g->rayDirX1 - g->rayDirX0) / WIDTH;
//      	g->floorStepY = g->rowDistance * (g->rayDirY1 - g->rayDirY0) / WIDTH;
// 		g->floorX = g->posx + g->rowDistance * g->rayDirX0;
//       	g->floorY = g->posy + g->rowDistance * g->rayDirY0;

// 		g->x = -1;
// 		while (++g->x < WIDTH)
// 		{
// 			g->cellX = (int)(g->floorX);
//         	g->cellY = (int)(g->floorY);
// 			g->tx = (int)(texWidth * (g->floorX - g->cellX)) & (texWidth - 1);
//         	g->ty = (int)(texHeight * (g->floorY - g->cellY)) & (texHeight - 1);
//        	 	g->floorX += g->floorStepX;
//         	g->floorY += g->floorStepY;
// 			int color = 0x174F80;
// 			ft_memcpy(g->imgpoke + 4 * WIDTH * g->x + g->y * 4,
// 					&color, sizeof(int));

// 		}

// 	}
// }


void      sprite_cast(t_game *g)
{
    g->sprite.y = 7.;
    g->sprite.x = 1.;
    printf("\n debug sprite %f \n", g->sprite.y);
    double spriteX = g->sprite.x - g->posx;
    double spriteY = g->sprite.y - g->posy;
    double invDet = 1.0 / (g->planex * g->diry - g->dirx * g->planey);
    double transformX = invDet * (g->diry * spriteX - g->dirx * spriteY);
    double transformY = invDet * (-g->planey * spriteX + g->planex * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

      int spriteScreenX = (int)((g->w / 2) * (1 + transformX / transformY));

      //calculate height of the sprite on screen
      int spriteHeight = abs((int)(g->h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      int drawStartY = -spriteHeight / 2 + g->h / 2;
      
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + g->h / 2;
      if(drawEndY >= g->h) drawEndY = g->h - 1;

      //calculate width of the sprite
      int spriteWidth = abs( (int) (g->h / (transformY)));
      int drawStartX = -spriteWidth / 2 + spriteScreenX;

      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= g->w) drawEndX = g->w - 1;
      int stripe = drawStartX;
      while ( stripe < drawStartX)
      {
        int sp_x = (int)(256 * (stripe - (-spriteWidth
			/ 2 + spriteScreenX)) * 64 /
			spriteWidth / 256);

          // sprite 
          int d;
          int y;

          y = drawStartY;
          if (transformY > 0 && stripe > 0 && stripe < g->w
            && transformY < g->ZBuffer[stripe])
          {
            while (y < drawEndX)
            {
              d = y * 256 - g->h * 128 + 64 * 128;
              int sp_y = ((d * 64) / 64) /
                256;
              int color = 0x00FF0000;
		          if (color != WALL_B)
		            memcpy(g->imgpoke + 4 * WIDTH * sp_y + sp_x * 4,
				          &color, sizeof(int));
              y++;
            }
          }



        stripe++;
      }

}

void        floor_cast(t_game *g)
{
      if(g->side == 0) g->x_wall = g->posy + g->perpwalldist * g->raydiry;
      else          g->x_wall = g->posx + g->perpwalldist * g->raydirx;
      g->x_wall -= floor((g->x_wall));

    if(g->side == 0 && g->raydirx > 0)
      {
        g->floorXWall = g->mapx;
        g->floorYWall = g->mapy + g->x_wall;
      }
      else if(g->side == 0 && g->raydirx < 0)
      {
        g->floorXWall = g->mapx + 1.0;
        g->floorYWall = g->mapy + g->x_wall;
      }
      else if(g->side == 1 && g->raydiry > 0)
      {
        g->floorXWall = g->mapx + g->x_wall;
        g->floorYWall = g->mapy;
      }
      else
      {
        g->floorXWall = g->mapx + g->x_wall;
        g->floorYWall = g->mapy + 1.0;
      }

      g->distWall = g->perpwalldist;
      g->distPlayer = 0.0;
      if(g->drawend < 0) g->drawend = g->h;
      int y = g->drawend;
      while(++y < g->h)
      {
        g->currentDist = g->h / (2.0 * y - g->h); //you could make a small lookup table for this instead

        g->weight = (g->currentDist - g->distPlayer) / (g->distWall - g->distPlayer);

        g->currentFloorX = g->weight * g->floorXWall + (1.0 - g->weight) * g->posx;
        g->currentFloorY = g->weight * g->floorYWall + (1.0 - g->weight) * g->posy;

        g->floorTexX = (int)(g->currentFloorX * texWidth) & (texWidth - 1);
        g->floorTexY = (int)(g->currentFloorY * texHeight) & (texHeight - 1);

		ft_memcpy(g->imgpoke + 4 * WIDTH * y + g->x * 4,
				&g->tex_arr[6].data[g->floorTexY % texWidth * g->tex_arr[6].sizeline +
				g->floorTexX % texWidth * g->tex_arr[6].bpp / 8], sizeof(int));
        // int color = 0x0B2D4B;
		// memcpy(g->imgpoke + 4 * WIDTH * y + g->x * 4,
		// 		&color, sizeof(int));

      }
}


void        sky_cast(t_game *g)
{
	if(g->side == 0)
        g->x_wall = g->posy + g->perpwalldist * g->raydiry;
    else
        g->x_wall = g->posx + g->perpwalldist * g->raydirx;
    g->x_wall -= floor((g->x_wall));

    if(g->side == 0 && g->raydirx > 0)
      {
        g->floorXWall = g->mapx;
        g->floorYWall = g->mapy + g->x_wall;
      }
      else if(g->side == 0 && g->raydirx < 0)
      {
        g->floorXWall = g->mapx + 1.0;
        g->floorYWall = g->mapy + g->x_wall;
      }
      else if(g->side == 1 && g->raydiry > 0)
      {
        g->floorXWall = g->mapx + g->x_wall;
        g->floorYWall = g->mapy;
      }
      else
      {
        g->floorXWall = g->mapx + g->x_wall;
        g->floorYWall = g->mapy + 1.0;
      }

      g->distWall = g->perpwalldist;
      g->distPlayer = 0.0;
      if(g->drawstart < 0) g->drawstart = 0;
      int y = 0;
      while(++y < g->drawstart)
      {
        g->currentDist = g->h / (2.0 * y - g->h); 

        g->weight = (g->currentDist - g->distPlayer) / (g->distWall - g->distPlayer);

        g->currentFloorX = g->weight * g->floorXWall + (1.0 - g->weight) * g->posx;
        g->currentFloorY = g->weight * g->floorYWall + (1.0 - g->weight) * g->posy;

        g->floorTexX = (int)(g->currentFloorX * texWidth) & (texWidth - 1);
        g->floorTexY = (int)(g->currentFloorY * texHeight) & (texHeight - 1);

		// ft_memcpy(g->imgpoke + 4 * WIDTH * y + g->x * 4,
		// 		&g->tex_arr[1].data[g->floorTexY % texWidth * g->tex_arr[1].sizeline +
		// 		g->floorTexX % texWidth * g->tex_arr[1].bpp / 8], sizeof(int));
        int color = 0x0B2D4B;
		memcpy(g->imgpoke + 4 * WIDTH * y + g->x * 4,
				&color, sizeof(int));

      }
}