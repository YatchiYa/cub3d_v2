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

void		ft_init_struct_save(t_game *storage, t_save *s)
{
	s->size = 54 + 4 * storage->w * storage->h;
	s->unused = 0;
	s->offset_begin = 54;
	s->header_bytes = 40;
	s->plane = 1;
	s->bpixel = 32;
	s->fd = open("img.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	if (s->fd == -1)
		exitit("Error :\n can't create screenshot.bmp \n check your valide space left device");
}

void		ft_write_texture_bmp_file(t_game *storage, int fd)
{
	int		y;
	int		x;
	int		line;

	y = 0;
	while (y < storage->h)
	{
		x = 0;
		line = storage->w * (storage->h - y);
		while (x < storage->w)
		{
			write(fd, &storage->imgpoke[line * 4], 4);
			line++;
			x++;
		}
		y++;
	}
}

void		ft_write_bmp_file(t_game *storage)
{
	t_save	s;

	ft_init_struct_save(storage, &s);
	write(s.fd, "BM", 2);
	write(s.fd, &s.size, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.offset_begin, sizeof(int));
	write(s.fd, &s.header_bytes, sizeof(int));
	write(s.fd, &storage->w, sizeof(int));
	write(s.fd, &storage->h, sizeof(int));
	write(s.fd, &s.plane, sizeof(short int));
	write(s.fd, &s.bpixel, sizeof(short int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	ft_write_texture_bmp_file(storage, s.fd);
	close(s.fd);
}

int			ft_bitmap(t_game *g)
{
	ft_write_bmp_file(g);
	close_win(g);
	return (0);
}
