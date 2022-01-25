/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_pars_ceiling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:36:28 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/30 16:37:41 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_parse_c2_first(char *tmp, t_all *all)
{
	char	*dst;
	char	**tmp2;
	int		i;

	tmp2 = ft_split(tmp, ' ');
	if (tmp2[2] != NULL)
		ft_error(8, all);
	i = 0;
	while (tmp2[1][i] != '\0')
	{
		if (!(ft_isdigit(tmp2[1][i])))
			ft_error(5, all);
		i++;
	}
	dst = ft_strdup(tmp2[1]);
	if (all->flag2->flag_for_c == 0)
		all->flag->color_r = ft_atoi(dst);
	else if (all->flag2->flag_for_c == 1)
		all->flag->color_g = ft_atoi(dst);
	else if (all->flag2->flag_for_c == 2)
		all->flag->color_b = ft_atoi(dst);
	all->flag2->flag_for_c++;
	free(dst);
	ft_free(tmp2);
}

void	ft_parse_c2(char *tmp, t_all *all)
{
	char	*dst;
	char	**tmp2;
	int		j;

	tmp2 = ft_split(tmp, ' ');
	if (tmp2[1] != NULL)
		ft_error(8, all);
	j = 0;
	while (tmp2[0][j] != '\0')
	{
		if (!(ft_isdigit(tmp2[0][j])))
			ft_error(5, all);
		j++;
	}
	dst = ft_strdup(tmp2[0]);
	if (all->flag2->flag_for_c == 0)
		all->flag->color_r = ft_atoi(dst);
	else if (all->flag2->flag_for_c == 1)
		all->flag->color_g = ft_atoi(dst);
	else if (all->flag2->flag_for_c == 2)
		all->flag->color_b = ft_atoi(dst);
	all->flag2->flag_for_c++;
	free(dst);
	ft_free(tmp2);
}

void	ft_parse_c3(t_all *all)
{
	if (all->flag->color_r > 255 || all->flag->color_g > 255 || \
			all->flag->color_b > 255)
		ft_error(8, all);
	all->texture->ceiling = create_rgb(all->flag->color_r, \
			all->flag->color_g, all->flag->color_b);
	all->flag2->f_c = 1;
	all->flag->pos_map++;
}

void	ft_parse_c(char *identifiers, t_all *all)
{
	char	**tmp;
	int		i;

	if (all->flag2->f_c == 1)
		ft_error(7, all);
	check_comma(identifiers, all);
	tmp = ft_split(identifiers, ',');
	if (tmp[0][0] != 'C' && tmp[0][1] != '\0')
		ft_error(5, all);
	if (tmp[0] == NULL || tmp[1] == NULL || tmp[2] == NULL || tmp[3] != NULL)
		ft_error(8, all);
	ft_parse_c2_first(tmp[0], all);
	ft_parse_c2(tmp[1], all);
	ft_parse_c2(tmp[2], all);
	ft_parse_c3(all);
	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	all->flag->f_i++;
}
