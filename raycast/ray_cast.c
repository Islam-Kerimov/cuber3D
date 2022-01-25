/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_ray_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 23:33:06 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/30 18:04:01 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_malloc_buf(t_all *all, int w, int h)
{
	int i;

	if (!(all->buf->buf = \
				(unsigned int **)malloc(h * sizeof(unsigned int*))))
		ft_error(14, all);
	i = 0;
	while (i < h)
	{
		if (!(all->buf->buf[i] = \
					(unsigned int *)malloc(w * sizeof(unsigned int))))
			ft_error(14, all);
		i++;
	}
	if (!(all->buf->spbuf = (double *)malloc(w * sizeof(double))))
		ft_error(14, all);
}

void	ft_put_image(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (i < all->size->screen_h)
	{
		j = 0;
		while (j < all->size->screen_w)
		{
			my_mlx_pixel_put(all->vars, j, i, all->buf->buf[i][j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < all->size->screen_h)
		free(all->buf->buf[i++]);
	free(all->buf->buf);
	free(all->buf->spbuf);
	mlx_put_image_to_window(all->vars->mlx, all->vars->win, \
			all->vars->img, 0, 0);
	mlx_destroy_image(all->vars->mlx, all->vars->img);
}

int		ft_draw_screen(t_all *all)
{
	int			w;
	int			h;
	t_buf		buf;
	t_ray		ray;
	t_bitmap	bitmap;

	all->buf = &buf;
	all->ray = &ray;
	all->bitmap = &bitmap;
	w = all->size->screen_w;
	h = all->size->screen_h;
	ft_malloc_buf(all, w, h);
	ft_wall_cast(all, w, h);
	ft_sprite_cast(all, w, h);
	free(all->sp->dist_sp);
	if (all->flag->argc == 3)
		ft_bitmap(all);
	all->vars->img = mlx_new_image(all->vars->mlx, \
			all->size->screen_w, all->size->screen_h);
	if (!all->vars->img)
		ft_error(13, all);
	all->vars->addr = mlx_get_data_addr(all->vars->img, \
			&all->vars->bpp, &all->vars->line_len, &all->vars->endian);
	ft_put_image(all);
	return (0);
}
