/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_init_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:34:57 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:14:19 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_init_struct3(t_all *all)
{
	all->flag2->f_c = 0;
	all->flag->f_d = 0;
	all->flag2->f_ea = 0;
	all->flag2->f_f = 0;
	all->flag->f_i = 0;
	all->flag->f_map = 0;
	all->flag2->f_no = 0;
	all->flag2->f_r = 0;
	all->flag2->f_s = 0;
	all->flag2->f_so = 0;
	all->flag2->f_we = 0;
	all->flag2->flag_for_c = 0;
	all->flag2->flag_for_f = 0;
	all->flag->flag_not_val = 0;
	all->flag->flag_one_player = 0;
	all->flag->k = 0;
	all->flag->last_k = 0;
	all->flag->last_pos_map = 0;
	all->flag->line_id = 0;
	all->flag->map_have = 0;
	all->flag->pos_map = 0;
	all->flag->color_r = 0;
	all->flag->color_g = 0;
	all->flag->color_b = 0;
}

static void	ft_init_struct2(t_all *all)
{
	all->txt->img_no = NULL;
	all->txt->addr_no = NULL;
	all->txt->img_so = NULL;
	all->txt->addr_so = NULL;
	all->txt->img_we = NULL;
	all->txt->addr_we = NULL;
	all->txt->img_ea = NULL;
	all->txt->addr_ea = NULL;
	all->txt->img_s = NULL;
	all->txt->addr_s = NULL;
	all->map = NULL;
	all->flag->n = 0;
	all->flag->n1 = 0;
	all->flag->n2 = 0;
	all->flag->n3 = 0;
	all->flag->n4 = 0;
	ft_init_struct3(all);
}

void		ft_init_struct(t_all *all)
{
	all->vars->mlx = NULL;
	all->vars->win = NULL;
	all->vars->img = NULL;
	all->vars->addr = NULL;
	all->pos->x = 0;
	all->pos->y = 0;
	all->sp->number_spr = 0;
	all->size->screen_w = 0;
	all->size->screen_h = 0;
	all->size->max_w = 0;
	all->size->max_h = 0;
	all->size->map_w = 0;
	all->size->map_h = 0;
	all->size->tex_w = 0;
	all->size->tex_h = 0;
	all->texture->no = NULL;
	all->texture->so = NULL;
	all->texture->we = NULL;
	all->texture->ea = NULL;
	all->texture->s = NULL;
	all->texture->floor = 0;
	all->texture->ceiling = 0;
	ft_init_struct2(all);
}
