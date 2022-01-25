/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:06:50 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:06:52 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#include <stdio.h>

void	ft_free_identifiers(char **identifiers, t_all *all)
{
	int i;

	i = 0;
	while (i < all->flag->line_id)
	{
		free(identifiers[i]);
		i++;
	}
	free(identifiers);
}

char	**ft_cat_map(char **map, t_all *all, char **identifiers)
{
	int ml;
	int tml;
	int i;

	map = ft_calloc(all->flag->line_id + 1 - \
			all->flag->pos_map, sizeof(char *));
	all->size->map_h = all->flag->line_id - all->flag->pos_map;
	ml = 0;
	tml = 0;
	i = 0;
	while (identifiers[all->flag->pos_map])
	{
		map[i] = ft_strdup(identifiers[all->flag->pos_map]);
		if (ml > tml)
			tml = ml;
		ml = ft_strlen(map[i++]);
		if (ml > tml)
			all->size->map_w = ml;
		all->flag->pos_map++;
	}
	ft_free_identifiers(identifiers, all);
	return (map);
}
