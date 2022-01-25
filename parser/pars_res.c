/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_pars_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:38:11 by ctanton           #+#    #+#             */
/*   Updated: 2021/04/04 18:21:21 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_save(char *tmp, t_all *all)
{
	size_t i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (!(ft_isdigit(tmp[i])))
			ft_error(5, all);
		i++;
	}
	i = 0;
	if (ft_strlen(tmp) > 5)
		ft_error(15, all);
	else if (ft_atoi(tmp) > 10000)
		ft_error(15, all);
	else if (*tmp == '0')
		ft_error(8, all);
	else if (ft_atoi(tmp) < 100)
		i = 100;
	else
		i = ft_atoi(tmp);
	if (all->size->screen_w == 0)
		all->size->screen_w = i;
	else if (all->size->screen_h == 0)
		all->size->screen_h = i;
	all->flag->f_d++;
}

void	ft_parse_r2(char *tmp, t_all *all)
{
	size_t	i;

	i = 0;
	if (all->flag->argc == 3)
		ft_save(tmp, all);
	else
	{
		while (tmp[i] != '\0')
		{
			if (!(ft_isdigit(tmp[i])))
				ft_error(5, all);
			i++;
		}
		if (ft_strlen(tmp) > 4)
			i = 9999;
		else
			i = ft_atoi(tmp);
		if (i < 100 && i != 0)
			i = 100;
		if (all->size->screen_w == 0)
			all->size->screen_w = i;
		else if (all->size->screen_h == 0)
			all->size->screen_h = i;
		all->flag->f_d++;
	}
}

void	ft_parse_r3(t_all *all)
{
	if (all->flag->argc == 2)
	{
		all->size->screen_w > all->size->max_w ? \
			all->size->screen_w = all->size->max_w : 0;
		all->size->screen_h > all->size->max_h ? \
			all->size->screen_h = all->size->max_h : 0;
	}
	if (all->size->screen_w == 0 || all->size->screen_h == 0 || \
			all->flag->f_d != 2)
		ft_error(8, all);
}

void	ft_parse_r(char *identifiers, t_all *all)
{
	char	**tmp;
	int		i;

	if (all->flag2->f_r == 1)
		ft_error(7, all);
	tmp = ft_split(identifiers, ' ');
	if (tmp[0][0] != 'R' && tmp[0][1] != '\0')
		ft_error(5, all);
	if (tmp[0] == NULL || tmp[1] == NULL || tmp[2] == NULL || tmp[3] != NULL)
		ft_error(5, all);
	ft_parse_r2(tmp[1], all);
	ft_parse_r2(tmp[2], all);
	all->flag2->f_r = 1;
	all->flag->pos_map++;
	ft_parse_r3(all);
	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	all->flag->f_i++;
}
