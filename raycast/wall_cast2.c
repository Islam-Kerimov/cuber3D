/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_wall_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:09:18 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 16:34:20 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_pos_ray_distanshion(t_all *all)
{
	all->ray->delta_x = fabs(1 / all->ray->x_ray);
	all->ray->delta_y = fabs(1 / all->ray->y_ray);
	all->ray->hit = 0;
	if (all->ray->x_ray < 0)
		all->ray->x_step = -1;
	else
		all->ray->x_step = 1;
	if (all->ray->x_ray < 0)
		all->ray->side_x = (all->plr->x_pos - all->ray->x_map) * \
						all->ray->delta_x;
	else
		all->ray->side_x = (all->ray->x_map + 1.0 - all->plr->x_pos) * \
						all->ray->delta_x;
	if (all->ray->y_ray < 0)
		all->ray->y_step = -1;
	else
		all->ray->y_step = 1;
	if (all->ray->y_ray < 0)
		all->ray->side_y = (all->plr->y_pos - all->ray->y_map) * \
						all->ray->delta_y;
	else
		all->ray->side_y = (all->ray->y_map + 1.0 - all->plr->y_pos) * \
						all->ray->delta_y;
}

void	ft_dda(t_all *all)
{
	while (all->ray->hit == 0)
	{
		if (all->ray->side_x < all->ray->side_y)
		{
			all->ray->side_x += all->ray->delta_x;
			all->ray->x_map += all->ray->x_step;
			all->ray->side = 0;
		}
		else
		{
			all->ray->side_y += all->ray->delta_y;
			all->ray->y_map += all->ray->y_step;
			all->ray->side = 1;
		}
		if (all->world_map[all->ray->y_map][all->ray->x_map] > 0)
			all->ray->hit = 1;
	}
}

void	ft_init_side_wall(t_all *all)
{
	if (all->ray->x_ray > 0 && all->ray->y_ray > 0 && all->ray->side == 0)
		all->ray->tex_n = 1;
	else if (all->ray->x_ray > 0 && all->ray->y_ray > 0 && all->ray->side == 1)
		all->ray->tex_n = 2;
	if (all->ray->x_ray > 0 && all->ray->y_ray < 0 && all->ray->side == 0)
		all->ray->tex_n = 1;
	else if (all->ray->x_ray > 0 && all->ray->y_ray < 0 && all->ray->side == 1)
		all->ray->tex_n = 0;
	if (all->ray->x_ray < 0 && all->ray->y_ray < 0 && all->ray->side == 0)
		all->ray->tex_n = 3;
	else if (all->ray->x_ray < 0 && all->ray->y_ray < 0 && all->ray->side == 1)
		all->ray->tex_n = 0;
	if (all->ray->x_ray < 0 && all->ray->y_ray > 0 && all->ray->side == 0)
		all->ray->tex_n = 3;
	else if (all->ray->x_ray < 0 && all->ray->y_ray > 0 && all->ray->side == 1)
		all->ray->tex_n = 2;
}

void	ft_lineheight_text(t_all *all, int h)
{
	if (all->ray->side == 0)
		all->plr->distance = (all->ray->x_map - all->plr->x_pos + \
				(1 - all->ray->x_step) / 2) / all->ray->x_ray;
	else
		all->plr->distance = (all->ray->y_map - all->plr->y_pos + \
				(1 - all->ray->y_step) / 2) / all->ray->y_ray;
	all->ray->h_line = (int)(h / all->plr->distance);
	all->ray->h_line = all->ray->h_line * 0.75 * \
					all->size->screen_w / all->size->screen_h;
	all->ray->s_line = h / 2 - all->ray->h_line / 2;
	if (all->ray->s_line < 0)
		all->ray->s_line = 0;
	all->ray->e_line = all->ray->h_line / 2 + h / 2;
	if (all->ray->e_line >= h)
		all->ray->e_line = h - 1;
	if (all->ray->side == 0)
		all->ray->wall = all->plr->y_pos + all->plr->distance * all->ray->y_ray;
	else
		all->ray->wall = all->plr->x_pos + all->plr->distance * all->ray->x_ray;
	all->ray->wall = all->ray->wall - floor(all->ray->wall);
	all->ray->tex_x = (int)(all->ray->wall * (double)(all->size->tex_w));
	if (all->ray->side == 0 && all->ray->x_ray < 0)
		all->ray->tex_x = all->size->tex_w - all->ray->tex_x - 1;
	if (all->ray->side == 1 && all->ray->y_ray > 0)
		all->ray->tex_x = all->size->tex_w - all->ray->tex_x - 1;
}
