/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_wall_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:09:18 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 16:26:52 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_cast_floor_ceiling(t_all *all, int h, int x)
{
	int y;

	y = 0;
	while (y < h / 2)
	{
		all->buf->buf[y][x] = all->texture->ceiling;
		y++;
	}
	while (y < h)
	{
		all->buf->buf[y][x] = all->texture->floor;
		y++;
	}
}

void	ft_verline(t_all *all, int h, int x)
{
	int		y;
	double	step;

	step = 1.0 * all->size->tex_h / all->ray->h_line;
	all->ray->pos_tex = (all->ray->s_line - h / 2 + \
			all->ray->h_line / 2) * step;
	y = all->ray->s_line;
	while (y < all->ray->e_line)
	{
		all->ray->tex_y = (int)all->ray->pos_tex & (all->size->tex_h - 1);
		all->ray->pos_tex += step;
		all->ray->color = my_mlx_pixel_take(all, \
				all->ray->tex_x, all->ray->tex_y);
		all->buf->buf[y][x] = all->ray->color;
		y++;
	}
}

void	ft_wall_cast(t_all *all, int w, int h)
{
	int x;

	x = 0;
	while (x < w)
	{
		all->ray->cam_x = 2 * x / (double)w - 1;
		all->ray->x_ray = all->plr->x_dir + all->plr->x_plane * all->ray->cam_x;
		all->ray->y_ray = all->plr->y_dir + all->plr->y_plane * all->ray->cam_x;
		all->ray->x_map = (int)(all->plr->x_pos);
		all->ray->y_map = (int)(all->plr->y_pos);
		ft_init_pos_ray_distanshion(all);
		ft_dda(all);
		ft_init_side_wall(all);
		ft_lineheight_text(all, h);
		ft_cast_floor_ceiling(all, h, x);
		ft_verline(all, h, x);
		all->buf->spbuf[x] = all->plr->distance;
		x++;
	}
}
