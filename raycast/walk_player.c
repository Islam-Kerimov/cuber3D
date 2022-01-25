/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_walk_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:01:03 by ctanton           #+#    #+#             */
/*   Updated: 2021/04/04 18:24:02 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_up_down(int keycode, t_all *all)
{
	if (keycode == 13)
	{
		if (all->world_map[(int)(all->plr->y_pos)]\
				[(int)(all->plr->x_pos + all->plr->x_dir * 0.5)] == 0)
			all->plr->x_pos += all->plr->x_dir * 0.5;
		if (all->world_map[(int)(all->plr->y_pos + all->plr->y_dir * \
					0.5)][(int)(all->plr->x_pos)] == 0)
			all->plr->y_pos += all->plr->y_dir * 0.5;
	}
	if (keycode == 1)
	{
		if (all->world_map[(int)(all->plr->y_pos)]\
				[(int)(all->plr->x_pos - all->plr->x_dir * 0.5)] == 0)
			all->plr->x_pos -= all->plr->x_dir * 0.5;
		if (all->world_map[(int)(all->plr->y_pos - all->plr->y_dir * \
					0.5)][(int)(all->plr->x_pos)] == 0)
			all->plr->y_pos -= all->plr->y_dir * 0.5;
	}
}

void	ft_left_right(int keycode, t_all *all)
{
	if (keycode == 2)
	{
		if (all->world_map[(int)(all->plr->y_pos)]\
				[(int)(all->plr->x_pos + all->plr->x_plane * 0.5)] == 0)
			all->plr->x_pos += all->plr->x_plane * 0.5;
		if (all->world_map[(int)(all->plr->y_pos + all->plr->y_plane * \
					0.5)][(int)(all->plr->x_pos)] == 0)
			all->plr->y_pos += all->plr->y_plane * 0.5;
	}
	if (keycode == 0)
	{
		if (all->world_map[(int)(all->plr->y_pos)]\
				[(int)(all->plr->x_pos - all->plr->x_plane * 0.5)] == 0)
			all->plr->x_pos -= all->plr->x_plane * 0.5;
		if (all->world_map[(int)(all->plr->y_pos - all->plr->y_plane * \
					0.5)][(int)(all->plr->x_pos)] == 0)
			all->plr->y_pos -= all->plr->y_plane * 0.5;
	}
}

void	ft_turnl_turnr(int keycode, t_all *all, double olddir, double oldplane)
{
	olddir = all->plr->x_dir;
	oldplane = all->plr->x_plane;
	if (keycode == 124)
	{
		all->plr->x_dir = all->plr->x_dir * cos(0.25) - \
						all->plr->y_dir * sin(0.25);
		all->plr->y_dir = olddir * sin(0.25) + \
						all->plr->y_dir * cos(0.25);
		all->plr->x_plane = all->plr->x_plane * cos(0.25) - \
						all->plr->y_plane * sin(0.25);
		all->plr->y_plane = oldplane * sin(0.25) + \
						all->plr->y_plane * cos(0.25);
	}
	if (keycode == 123)
	{
		all->plr->x_dir = all->plr->x_dir * cos(-0.25) - \
						all->plr->y_dir * sin(-0.25);
		all->plr->y_dir = olddir * sin(-0.25) + \
						all->plr->y_dir * cos(-0.25);
		all->plr->x_plane = all->plr->x_plane * cos(-0.25) - \
						all->plr->y_plane * sin(-0.25);
		all->plr->y_plane = oldplane * sin(-0.25) + \
						all->plr->y_plane * cos(-0.25);
	}
}

void	ft_esc(int keycode, t_all *all)
{
	if (keycode == 53)
		close_all(all);
}

int		key_press(int keycode, t_all *all)
{
	double oldxdir;
	double oldxplane;

	oldxplane = 0;
	oldxdir = 0;
	mlx_clear_window(all->vars->mlx, all->vars->win);
	ft_up_down(keycode, all);
	ft_left_right(keycode, all);
	ft_turnl_turnr(keycode, all, oldxdir, oldxplane);
	ft_esc(keycode, all);
	ft_draw_screen(all);
	return (0);
}
