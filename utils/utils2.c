/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:09:12 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 16:23:09 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_len + x * (vars->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	my_mlx_pixel_take(t_all *all, int x, int y)
{
	char	*dst;

	if (all->ray->tex_n == 0)
		dst = all->txt->addr_no + (y * all->txt->line_len_no + \
				x * (all->txt->bpp_no / 8));
	if (all->ray->tex_n == 1)
		dst = all->txt->addr_ea + (y * all->txt->line_len_ea + \
				x * (all->txt->bpp_ea / 8));
	if (all->ray->tex_n == 2)
		dst = all->txt->addr_so + (y * all->txt->line_len_so + \
				x * (all->txt->bpp_so / 8));
	if (all->ray->tex_n == 3)
		dst = all->txt->addr_we + (y * all->txt->line_len_we + \
				x * (all->txt->bpp_we / 8));
	return (*(unsigned int*)dst);
}

void			ft_free_all(t_all *all)
{
	if (all->flag->argc == 53)
	{
		mlx_clear_window(all->vars->mlx, all->vars->win);
		mlx_destroy_window(all->vars->mlx, all->vars->win);
	}
	all->vars->mlx != NULL ? free(all->vars->mlx) : 0;
	all->texture->no != NULL ? free(all->texture->no) : 0;
	all->texture->so != NULL ? free(all->texture->so) : 0;
	all->texture->we != NULL ? free(all->texture->we) : 0;
	all->texture->ea != NULL ? free(all->texture->ea) : 0;
	all->texture->s != NULL ? free(all->texture->s) : 0;
	all->txt->img_no != NULL ? free(all->txt->img_no) : 0;
	all->txt->addr_no != NULL ? free(all->txt->addr_no) : 0;
	all->txt->img_so != NULL ? free(all->txt->img_so) : 0;
	all->txt->addr_so != NULL ? free(all->txt->addr_so) : 0;
	all->txt->img_we != NULL ? free(all->txt->img_we) : 0;
	all->txt->addr_we != NULL ? free(all->txt->addr_we) : 0;
	all->txt->img_ea != NULL ? free(all->txt->img_ea) : 0;
	all->txt->addr_ea != NULL ? free(all->txt->addr_ea) : 0;
	all->txt->img_s != NULL ? free(all->txt->img_s) : 0;
	all->txt->addr_s != NULL ? free(all->txt->addr_s) : 0;
	free_world_map_sprites(all);
}

void			ft_error(int error, t_all *all)
{
	error == 1 ? write(1, "Error\nWrong number of arguments\n", 32) : 0;
	error == 2 ? write(1, "Error\nThe sec arg should be '--save'\n", 37) : 0;
	error == 3 ? write(1, "Error\nFile could not be opened\n", 31) : 0;
	error == 4 ? write(1, "Error\nInvalid argument format\n", 30) : 0;
	error == 5 ? write(1, "Error\nInvalid init of the scene\n", 32) : 0;
	error == 6 ? write(1, "Error\nWrong number of identifiers\n", 34) : 0;
	error == 7 ? write(1, "Error\nIdentifiers must not be repeated\n", 39) : 0;
	error == 8 ? write(1, "Error\nParameters are incorrect\n", 31) : 0;
	error == 9 ? write(1, "Error\nDon't overflow\n", 21) : 0;
	error == 10 ? write(1, "Error\nInvalid map\n", 18) : 0;
	error == 11 ? write(1, "Error\nEmpty map\n", 16) : 0;
	error == 12 ? write(1, "Error\nThere must be one player\n", 31) : 0;
	error == 13 ? write(1, "Error\nSome function mlx returned NULL\n", 38) : 0;
	error == 14 ? write(1, "Error\nMemory not allocated\n", 27) : 0;
	error == 15 ? write(1, "Error\nToo large for the screen, ", 32) : 0;
	error == 15 ? write(1, "or you get tired of waiting for the ", 36) : 0;
	error == 15 ? write(1, "program to compile, or it will crash, ", 38) : 0;
	error == 15 ? write(1, "who needs it\n", 13) : 0;
	ft_free_all(all);
	exit(0);
}

int				close_all(t_all *all)
{
	all->flag->argc = 53;
	ft_free_all(all);
	exit(0);
	return (0);
}
