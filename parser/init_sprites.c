/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_ft_init_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:30:44 by ctanton           #+#    #+#             */
/*   Updated: 2021/04/04 18:21:44 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_malloc_sprites(char **map, t_all *all)
{
	int i;

	all->pos->y = 0;
	i = 0;
	while (map[all->pos->y])
	{
		all->pos->x = 0;
		while (map[all->pos->y][all->pos->x])
		{
			if (map[all->pos->y][all->pos->x] == '2')
				all->sp->number_spr++;
			all->pos->x++;
		}
		all->pos->y++;
	}
	if (!(all->sp->x = (double *)malloc(all->sp->number_spr * sizeof(double))))
		ft_error(14, all);
	if (!(all->sp->y = (double *)malloc(all->sp->number_spr * sizeof(double))))
		ft_error(14, all);
}

void	ft_init_sprites(char **map, t_all *all)
{
	int i;

	ft_malloc_sprites(map, all);
	all->pos->y = 0;
	i = 0;
	while (map[all->pos->y])
	{
		all->pos->x = 0;
		while (map[all->pos->y][all->pos->x])
		{
			if (map[all->pos->y][all->pos->x] == '2')
			{
				all->sp->x[i] = (double)all->pos->x + 0.5;
				all->sp->y[i] = (double)all->pos->y + 0.5;
				i++;
				map[all->pos->y][all->pos->x] = '0';
			}
			all->pos->x++;
		}
		all->pos->y++;
	}
}
