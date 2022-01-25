/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_sprite_cast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:49:05 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 16:52:09 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_sort_sprites(t_all *all, int i, int j)
{
	while (i >= 0)
	{
		all->sp->dis_tmp = 1;
		j = 0;
		while (j < i)
		{
			if (all->sp->dist_sp[j] < all->sp->dist_sp[j + 1])
			{
				all->sp->temp = all->sp->dist_sp[j];
				all->sp->dist_sp[j] = all->sp->dist_sp[j + 1];
				all->sp->dist_sp[j + 1] = all->sp->temp;
				all->sp->temp = all->sp->x[j];
				all->sp->x[j] = all->sp->x[j + 1];
				all->sp->x[j + 1] = all->sp->temp;
				all->sp->temp = all->sp->y[j];
				all->sp->y[j] = all->sp->y[j + 1];
				all->sp->y[j + 1] = all->sp->temp;
				all->sp->dis_tmp = 0;
			}
			j++;
		}
		if (all->sp->dis_tmp == 1)
			break ;
		i--;
	}
}

void	ft_sprite_height(t_all *all, int w, int h)
{
	all->sp->scale = 1.0 / (all->plr->x_plane * \
			all->plr->y_dir - all->plr->x_dir * all->plr->y_plane);
	all->sp->turn_x = all->sp->scale * (all->plr->y_dir * \
			all->sp->sp_x - all->plr->x_dir * all->sp->sp_y);
	all->sp->turn_y = all->sp->scale * (-all->plr->y_plane * \
			all->sp->sp_x + all->plr->x_plane * all->sp->sp_y);
	all->sp->sp_screen = (int)((w / 2) * \
			(1 + all->sp->turn_x / all->sp->turn_y));
	all->sp->h_sprite = abs((int)(h / all->sp->turn_y));
	all->sp->h_sprite = all->sp->h_sprite * 0.75 * \
						all->size->screen_w / all->size->screen_h;
	all->sp->start_y = -all->sp->h_sprite / 2 + h / 2;
	if (all->sp->start_y < 0)
		all->sp->start_y = 0;
	all->sp->end_y = all->sp->h_sprite / 2 + h / 2;
	if (all->sp->end_y >= h)
		all->sp->end_y = h - 1;
	all->sp->sprite_w = abs((int)(h / all->sp->turn_y));
	all->sp->sprite_w *= 0.75 * all->size->screen_w / all->size->screen_h;
	all->sp->start_x = -all->sp->sprite_w / 2 + all->sp->sp_screen;
	if (all->sp->start_x < 0)
		all->sp->start_x = 0;
	all->sp->end_x = all->sp->sprite_w / 2 + all->sp->sp_screen;
	if (all->sp->end_x >= w)
		all->sp->end_x = w - 1;
}

void	ft_print_sprites2(t_all *all, int h, int d, int y)
{
	d = (y) * 256 - h * 128 + all->sp->h_sprite * 128;
	all->sp->sp_tex_y = ((d * all->size->tex_h) / all->sp->h_sprite) / 256;
	all->sp->color = *(unsigned int *)(all->txt->addr_s + \
			(all->sp->sp_tex_y * all->txt->line_len_s + \
			all->sp->sp_tex_x * (all->txt->bpp_s / 8)));
	if ((all->sp->color & 0xFFFFFF) != 0)
		all->buf->buf[y][all->sp->sprite] = all->sp->color;
}

void	ft_print_sprites(t_all *all, int w, int h)
{
	int d;
	int y;

	d = 0;
	all->sp->sprite = all->sp->start_x;
	while (all->sp->sprite < all->sp->end_x)
	{
		all->sp->sp_tex_x = (int)(256 * (all->sp->sprite - \
					(-all->sp->sprite_w / 2 + all->sp->sp_screen)) * \
				all->size->tex_w / all->sp->sprite_w) / 256;
		if (all->sp->turn_y > 0 && all->sp->sprite > 0 && \
				all->sp->sprite < w && \
				all->sp->turn_y < all->buf->spbuf[all->sp->sprite])
		{
			y = all->sp->start_y;
			while (y < all->sp->end_y)
			{
				ft_print_sprites2(all, h, d, y);
				y++;
			}
		}
		all->sp->sprite++;
	}
}

void	ft_sprite_cast(t_all *all, int w, int h)
{
	int i;
	int j;

	j = 0;
	if (!(all->sp->dist_sp = \
				(double *)malloc(all->sp->number_spr * sizeof(double))))
		ft_error(14, all);
	i = 0;
	while (i < all->sp->number_spr)
	{
		all->sp->dist_sp[i] = ((all->plr->x_pos - all->sp->x[i]) * \
				(all->plr->x_pos - all->sp->x[i]) + (all->plr->y_pos - \
					all->sp->y[i]) * (all->plr->y_pos - all->sp->y[i]));
		i++;
	}
	i = all->sp->number_spr - 1;
	ft_sort_sprites(all, i, j);
	i = 0;
	while (i < all->sp->number_spr)
	{
		all->sp->sp_x = all->sp->x[i] - all->plr->x_pos;
		all->sp->sp_y = all->sp->y[i++] - all->plr->y_pos;
		ft_sprite_height(all, w, h);
		ft_print_sprites(all, w, h);
	}
}
