/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:01:48 by ctanton           #+#    #+#             */
/*   Updated: 2021/04/04 18:24:50 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char			*ft_strnew(size_t size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc((size + 1) * sizeof(*tmp))))
		return (NULL);
	tmp[size] = '\0';
	while (size--)
		tmp[size] = '\0';
	return (tmp);
}

int				create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void			free_world_map_sprites(t_all *all)
{
	int i;

	free(all->sp->x);
	free(all->sp->y);
	i = 0;
	while (i < all->size->map_h)
		free(all->world_map[i++]);
	free(all->world_map);
}

void			ft_malloc_world_map(t_all *all)
{
	int i;

	if (!(all->world_map = \
				(int **)ft_calloc(all->size->map_h, sizeof(int*))))
		ft_error(14, all);
	i = 0;
	while (i < all->size->map_h)
	{
		if (!(all->world_map[i] = \
					(int *)ft_calloc(all->size->map_w, sizeof(int))))
			ft_error(14, all);
		i++;
	}
}

void			ft_map(t_all *all)
{
	int		j;
	int		i;

	ft_malloc_world_map(all);
	i = 0;
	while (i < all->size->map_h)
	{
		j = 0;
		while (j < all->size->map_w)
		{
			all->world_map[i][j] = all->map[i][j] - '0';
			j++;
		}
		i++;
	}
	i = 0;
	while (i < all->size->map_h)
	{
		free(all->map[i]);
		i++;
	}
	free(all->map);
}
