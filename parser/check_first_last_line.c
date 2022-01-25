/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_last_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:07:42 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:07:43 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_line(char *identifiers, t_all *all, int k)
{
	int s;

	if (*identifiers == ' ')
	{
		s = 0;
		while (identifiers[s] != '\0' && identifiers[s] == ' ')
			s++;
		if (identifiers[s] == '\0')
			k++;
		else
			all->flag->f_map = 1;
	}
	else
		k++;
	if (k == all->flag->line_id)
		ft_error(11, all);
	return (k);
}

void	ft_line2(char *identifiers, t_all *all)
{
	if ((ft_strchr(identifiers, '1') || ft_strchr(identifiers, ' ')) && \
	(!(ft_strchr(identifiers, '0'))) && !(ft_strchr(identifiers, '2')) && \
	!(ft_strchr(identifiers, 'N')) && !(ft_strchr(identifiers, 'S')) && \
	!(ft_strchr(identifiers, 'E')) && !(ft_strchr(identifiers, 'W')))
		all->flag->f_map = 2;
	else
		ft_error(10, all);
}

void	ft_line3(char **iden, t_all *all, int k, int lk)
{
	lk = k;
	while (iden[lk])
	{
		if (ft_strchr(iden[lk], '1'))
		{
			lk++;
			all->flag->map_have = 1;
		}
		else if (ft_strchr(iden[lk], ' '))
			lk++;
		else if (*iden[lk] == '\0')
			ft_error(10, all);
	}
	if (lk == all->flag->line_id && all->flag->map_have == 0)
		ft_error(11, all);
	lk--;
	if (ft_strchr(iden[lk], '0') || ft_strchr(iden[lk], '2') || \
			ft_strchr(iden[lk], 'N') || ft_strchr(iden[lk], 'S') || \
			ft_strchr(iden[lk], 'E') || ft_strchr(iden[lk], 'W'))
		ft_error(10, all);
	all->flag->f_map = 3;
	all->flag->k = k;
	all->flag->last_k = lk;
}

char	**check_f_l_line(char **identifiers, t_all *all)
{
	int k;
	int last_k;

	k = all->flag->pos_map;
	last_k = 0;
	while (all->flag->f_map != 3)
	{
		if (k == all->flag->line_id)
			ft_error(11, all);
		while ((*identifiers[k] == '\0' || *identifiers[k] == ' ') && \
				all->flag->f_map == 0)
			k = ft_line(identifiers[k], all, k);
		if (*identifiers[k] != '\0' && all->flag->f_map == 0)
			all->flag->f_map = 1;
		if (*identifiers[k] == '\0' && all->flag->f_map > 0)
			ft_error(10, all);
		if (all->flag->f_map == 1)
			ft_line2(identifiers[k], all);
		if (all->flag->f_map == 2)
			ft_line3(identifiers, all, k, last_k);
	}
	all->flag->last_pos_map = all->flag->last_k;
	all->flag->pos_map = all->flag->k;
	return (identifiers);
}

char	**check_f_l_line_for_one_or_zero(char **iden, t_all *all)
{
	int k;
	int last_k;

	last_k = all->flag->last_pos_map;
	k = all->flag->pos_map;
	while (k <= last_k)
	{
		if (iden[k][0] == '1' || iden[k][0] == ' ')
			k++;
		else
			ft_error(10, all);
	}
	k = all->flag->pos_map;
	last_k = all->flag->last_pos_map;
	while (k <= last_k)
	{
		if (iden[k][ft_strlen(iden[k]) - 1] == '1' || \
				iden[k][ft_strlen(iden[k]) - 1] == ' ')
			k++;
		else
			ft_error(10, all);
	}
	return (iden);
}
