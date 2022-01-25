/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one_plr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:07:54 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:07:56 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**check_one_plr(char **identifiers, t_all *all)
{
	int k;
	int last_k;
	int n;

	last_k = all->flag->last_pos_map;
	k = all->flag->pos_map;
	while (k <= last_k)
	{
		n = 0;
		while (identifiers[k][n])
		{
			if (identifiers[k][n] == 'N' || identifiers[k][n] == 'S' || \
					identifiers[k][n] == 'W' || identifiers[k][n] == 'E')
				all->flag->flag_one_player++;
			n++;
		}
		k++;
	}
	if (all->flag->flag_one_player++ != 1)
		ft_error(12, all);
	return (identifiers);
}
