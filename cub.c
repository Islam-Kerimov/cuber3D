/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:19:58 by ctanton           #+#    #+#             */
/*   Updated: 2021/04/04 18:25:35 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init4(t_all *all)
{
	if (!all->txt->img_no || !all->txt->img_so || !all->txt->img_we || \
			!all->txt->img_ea || !all->txt->img_s)
		ft_error(13, all);
	if (all->flag->argc == 2)
	{
		mlx_hook(all->vars->win, 2, 1L << 0, &key_press, all);
		mlx_hook(all->vars->win, 17, 0L, &close_all, all);
	}
	mlx_loop_hook(all->vars->mlx, &ft_draw_screen, all);
	mlx_loop(all->vars->mlx);
}

static void	ft_init3(t_all *all)
{
	if ((all->txt->img_no = mlx_xpm_file_to_image(all->vars->mlx, \
			all->texture->no, &all->size->tex_w, &all->size->tex_h)) == NULL)
		ft_error(3, all);
	all->txt->addr_no = mlx_get_data_addr(all->txt->img_no, \
			&all->txt->bpp_no, &all->txt->line_len_no, &all->txt->endian_no);
	if ((all->txt->img_so = mlx_xpm_file_to_image(all->vars->mlx, \
			all->texture->so, &all->size->tex_w, &all->size->tex_h)) == NULL)
		ft_error(3, all);
	all->txt->addr_so = mlx_get_data_addr(all->txt->img_so, \
			&all->txt->bpp_so, &all->txt->line_len_so, &all->txt->endian_so);
	if ((all->txt->img_we = mlx_xpm_file_to_image(all->vars->mlx, \
			all->texture->we, &all->size->tex_w, &all->size->tex_h)) == NULL)
		ft_error(3, all);
	all->txt->addr_we = mlx_get_data_addr(all->txt->img_we, \
			&all->txt->bpp_we, &all->txt->line_len_we, &all->txt->endian_we);
	if ((all->txt->img_ea = mlx_xpm_file_to_image(all->vars->mlx, \
			all->texture->ea, &all->size->tex_w, &all->size->tex_h)) == NULL)
		ft_error(3, all);
	all->txt->addr_ea = mlx_get_data_addr(all->txt->img_ea, \
			&all->txt->bpp_ea, &all->txt->line_len_ea, &all->txt->endian_ea);
	if ((all->txt->img_s = mlx_xpm_file_to_image(all->vars->mlx, \
			all->texture->s, &all->size->tex_w, &all->size->tex_h)) == NULL)
		ft_error(3, all);
	all->txt->addr_s = mlx_get_data_addr(all->txt->img_s, \
			&all->txt->bpp_s, &all->txt->line_len_s, &all->txt->endian_s);
}

static void	ft_init2(t_all *all)
{
	if (all->flag->argc == 3)
		if (!(ft_strncmp(all->flag->argv[2], "--save", \
						ft_strlen("--save")) == 0 && \
					ft_strlen(all->flag->argv[2]) == ft_strlen("--save")))
			ft_error(2, all);
	mlx_get_screen_size(&all->size->max_w, &all->size->max_h);
	all->map = ft_read_map(all);
	ft_map(all);
	all->vars->mlx = mlx_init();
	if (!all->vars->mlx)
		ft_error(13, all);
	if (all->flag->argc == 2)
	{
		all->vars->win = mlx_new_window(all->vars->mlx, \
				all->size->screen_w, all->size->screen_h, "ctanton");
		if (!all->vars->win)
			ft_error(13, all);
	}
}

static void	ft_init(t_all *all, int argc, char **argv)
{
	t_plr		plr;
	t_sprite	sp;
	t_flag		flag;
	t_point		pos;
	t_flag2		flag2;

	all->flag2 = &flag2;
	all->plr = &plr;
	all->sp = &sp;
	all->flag = &flag;
	all->pos = &pos;
	ft_init_struct(all);
	all->flag->argc = argc;
	all->flag->argv = argv;
	if (all->flag->argc != 2 && all->flag->argc != 3)
		ft_error(1, all);
	ft_init2(all);
	ft_init3(all);
	ft_init4(all);
}

int			main(int argc, char **argv)
{
	t_all		all;
	t_vars		vars;
	t_size		size;
	t_txt		txt;
	t_textur	texture;

	all.vars = &vars;
	all.size = &size;
	all.txt = &txt;
	all.texture = &texture;
	ft_init(&all, argc, argv);
	return (0);
}
