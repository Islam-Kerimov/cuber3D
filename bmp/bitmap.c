/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_bitmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:10:35 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/30 16:16:39 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			ft_init_header(t_all *all, int fd)
{
	int i;

	i = 0;
	while (i < all->bitmap->header_size)
		all->bitmap->file_head[i++] = 0;
	all->bitmap->file_head[0] = (unsigned char)('B');
	all->bitmap->file_head[1] = (unsigned char)('M');
	all->bitmap->file_head[2] = (unsigned char)(all->bitmap->file_size);
	all->bitmap->file_head[3] = (unsigned char)(all->bitmap->file_size >> 8);
	all->bitmap->file_head[4] = (unsigned char)(all->bitmap->file_size >> 16);
	all->bitmap->file_head[5] = (unsigned char)(all->bitmap->file_size >> 24);
	all->bitmap->file_head[10] = (unsigned char)(all->bitmap->header_size + \
			all->bitmap->info_size);
	i = 0;
	while (i < all->bitmap->header_size)
		ft_putchar_fd(all->bitmap->file_head[i++], fd);
}

void			ft_init_info(t_all *all, int fd)
{
	int i;

	i = 0;
	while (i < all->bitmap->info_size)
		all->bitmap->info_head[i++] = 0;
	all->bitmap->info_head[0] = (unsigned char)(all->bitmap->info_size);
	all->bitmap->info_head[4] = (unsigned char)(all->size->screen_w);
	all->bitmap->info_head[5] = (unsigned char)(all->size->screen_w >> 8);
	all->bitmap->info_head[6] = (unsigned char)(all->size->screen_w >> 16);
	all->bitmap->info_head[7] = (unsigned char)(all->size->screen_w >> 24);
	all->bitmap->info_head[8] = (unsigned char)(all->size->screen_h);
	all->bitmap->info_head[9] = (unsigned char)(all->size->screen_h >> 8);
	all->bitmap->info_head[10] = (unsigned char)(all->size->screen_h >> 16);
	all->bitmap->info_head[11] = (unsigned char)(all->size->screen_h >> 24);
	all->bitmap->info_head[12] = (unsigned char)(1);
	all->bitmap->info_head[14] = (unsigned char)(24);
	i = 0;
	while (i < all->bitmap->info_size)
		ft_putchar_fd(all->bitmap->info_head[i++], fd);
}

unsigned int	take_color(unsigned int buffer)
{
	unsigned int	rgb;

	rgb = (buffer & 0xFF0000) | (buffer & 0x00FF00) | (buffer & 0x0000FF);
	return (rgb);
}

void			ft_put_bmp(t_all *all, int fd)
{
	int				i;
	int				j;
	unsigned int	color;

	i = all->size->screen_h;
	while (--i >= 0)
	{
		j = 0;
		while (j < all->size->screen_w)
		{
			color = take_color(all->buf->buf[i][j]);
			write(fd, &color, 3);
			if (all->bitmap->padd > 0)
				write(fd, &all->bitmap->bmppad, all->bitmap->padd);
			j++;
		}
	}
	i = 0;
	while (i < all->size->screen_h)
		free(all->buf->buf[i++]);
	free(all->buf->buf);
	free(all->buf->spbuf);
}

void			ft_bitmap(t_all *all)
{
	int fd;

	fd = open("screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		ft_error(3, all);
	all->bitmap->bmppad = 0;
	all->bitmap->padd = ((4 - (all->size->screen_w * 3) % 4) % 4);
	all->bitmap->header_size = 14;
	all->bitmap->info_size = 40;
	all->bitmap->file_size = all->bitmap->header_size + \
							all->bitmap->info_size + all->size->screen_w * \
							all->size->screen_h * 3 + \
							all->bitmap->padd * all->size->screen_h;
	ft_init_header(all, fd);
	ft_init_info(all, fd);
	ft_put_bmp(all, fd);
	ft_free_all(all);
	exit(0);
}
