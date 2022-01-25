/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_val_play.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:07:21 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:07:22 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	identification_flags(t_all *all)
{
	all->flag->n = 0;
	all->flag->n1 = 0;
	all->flag->n2 = 0;
	all->flag->n3 = 0;
	all->flag->n4 = 0;
}

void	ft_check_for_8(char **iden, t_all *all, int k)
{
	if (iden[k][all->flag->n] == '0' || iden[k][all->flag->n] == '2' || \
			iden[k][all->flag->n] == 'N' || iden[k][all->flag->n] == 'S' || \
			iden[k][all->flag->n] == 'W' || iden[k][all->flag->n] == 'E')
	{
		all->flag->n1 = all->flag->n;
		all->flag->n2 = ft_strlen(iden[k - 1]) - 1;
		all->flag->n4 = ft_strlen(iden[k + 1]) - 1;
		if (all->flag->n2 < all->flag->n1 || all->flag->n4 < all->flag->n1)
			ft_error(10, all);
	}
	if (iden[k][all->flag->n] == '0' || iden[k][all->flag->n] == '2' || \
			iden[k][all->flag->n] == 'N' || iden[k][all->flag->n] == 'S' || \
			iden[k][all->flag->n] == 'W' || iden[k][all->flag->n] == 'E')
	{
		if ((iden[k][all->flag->n1 - 1] == ' ' || \
					iden[k][all->flag->n1 + 1] == ' ' || \
					iden[k + 1][all->flag->n1] == ' ' || \
					iden[k - 1][all->flag->n1] == ' '))
			ft_error(10, all);
	}
}

char	**check_zero(char **identifiers, t_all *all)
{
	int k;
	int last_k;

	last_k = all->flag->last_pos_map;
	k = all->flag->pos_map;
	while (k <= last_k)
	{
		if (ft_strchr(identifiers[k], '0'))
		{
			all->flag->n = 0;
			while (all->flag->n < (all->flag->n3 = \
						ft_strlen(identifiers[k]) - 1))
			{
				all->flag->n1 = 0;
				ft_check_for_8(identifiers, all, k);
				all->flag->n++;
			}
			k++;
		}
		else
			k++;
	}
	return (identifiers);
}

char	**check_2(char **identifiers, t_all *all)
{
	int k;
	int last_k;

	k = all->flag->pos_map;
	last_k = all->flag->last_pos_map;
	identification_flags(all);
	while (k <= last_k)
	{
		if (ft_strchr(identifiers[k], '2'))
		{
			all->flag->n = 0;
			while (all->flag->n < (all->flag->n3 = \
						ft_strlen(identifiers[k]) - 1))
			{
				all->flag->n1 = 0;
				ft_check_for_8(identifiers, all, k);
				all->flag->n++;
			}
			k++;
		}
		else
			k++;
	}
	return (identifiers);
}

char	**check_plr(char **iden, t_all *all)
{
	int k;
	int last_k;

	k = all->flag->pos_map;
	last_k = all->flag->last_pos_map;
	identification_flags(all);
	while (k <= last_k)
	{
		if (ft_strchr(iden[k], 'N') || ft_strchr(iden[k], 'S') || \
				ft_strchr(iden[k], 'W') || \
				ft_strchr(iden[k], 'E'))
		{
			all->flag->n = 0;
			while (all->flag->n < (all->flag->n3 = ft_strlen(iden[k]) - 1))
			{
				all->flag->n1 = 0;
				ft_check_for_8(iden, all, k);
				all->flag->n++;
			}
			k++;
		}
		else
			k++;
	}
	return (iden);
}
