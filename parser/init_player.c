/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_ft_init_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:54:08 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 15:57:24 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_pos_n_s(t_all *all, char c)
{
	all->plr->x_pos = (double)all->pos->x + 0.5;
	all->plr->y_pos = (double)all->pos->y + 0.5;
	if (c == 'N')
	{
		all->plr->x_dir = 0;
		all->plr->y_dir = -1;
		all->plr->x_plane = 0.66;
		all->plr->y_plane = 0;
	}
	else if (c == 'S')
	{
		all->plr->x_dir = 0;
		all->plr->y_dir = 1;
		all->plr->x_plane = -0.66;
		all->plr->y_plane = 0;
	}
}

void	ft_init_pos_w_e(t_all *all, char c)
{
	all->plr->x_pos = (double)all->pos->x + 0.5;
	all->plr->y_pos = (double)all->pos->y + 0.5;
	if (c == 'W')
	{
		all->plr->x_dir = -1;
		all->plr->y_dir = 0;
		all->plr->x_plane = 0;
		all->plr->y_plane = -0.66;
	}
	else if (c == 'E')
	{
		all->plr->x_dir = 1;
		all->plr->y_dir = 0;
		all->plr->x_plane = 0;
		all->plr->y_plane = 0.66;
	}
}

void	ft_init_player(char **map, t_all *all)
{
	all->plr->flag_pos_plr = 0;
	while (map[all->pos->y])
	{
		all->pos->x = 0;
		while (map[all->pos->y][all->pos->x])
		{
			if (map[all->pos->y][all->pos->x] == 'N' || \
					map[all->pos->y][all->pos->x] == 'S')
			{
				ft_init_pos_n_s(all, map[all->pos->y][all->pos->x]);
				map[all->pos->y][all->pos->x] = '0';
			}
			else if (map[all->pos->y][all->pos->x] == 'W' || \
					map[all->pos->y][all->pos->x] == 'E')
			{
				ft_init_pos_w_e(all, map[all->pos->y][all->pos->x]);
				map[all->pos->y][all->pos->x] = '0';
			}
			all->pos->x++;
		}
		all->pos->y++;
	}
}
