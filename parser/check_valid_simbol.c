/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_simbol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:08:18 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:08:19 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**check_valid_simbol(char **identifiers, t_all *all)
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
					identifiers[k][n] == 'W' || identifiers[k][n] == 'E' || \
					identifiers[k][n] == '0' || identifiers[k][n] == '1' || \
					identifiers[k][n] == '2' || identifiers[k][n] == ' ')
				n++;
			else
				all->flag->flag_not_val = 1;
		}
		k++;
	}
	if (all->flag->flag_not_val != 0)
		ft_error(10, all);
	return (identifiers);
}
