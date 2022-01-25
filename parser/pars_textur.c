/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_pars_textur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:38:29 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/30 16:38:39 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_parse_s(char *identifiers, t_all *all)
{
	char	*tmp;
	int		j;
	int		fd;

	if (all->flag2->f_s == 1)
		ft_error(7, all);
	tmp = ft_strdup(identifiers);
	free(tmp);
	tmp = ft_strtrim(&identifiers[2], " ");
	j = 0;
	while (tmp[j])
	{
		if (tmp[j] == ' ')
			ft_error(8, all);
		j++;
	}
	all->texture->s = tmp;
	if ((fd = open(all->texture->s, O_RDONLY)) == -1)
		ft_error(3, all);
	close(fd);
	all->flag2->f_s = 1;
	all->flag->pos_map++;
	all->flag->f_i++;
	ft_chech_txt_fotmat(all->texture->s, all);
}

void	ft_parse_no(char *identifiers, t_all *all)
{
	char	*tmp;
	int		j;
	int		fd;

	if (all->flag2->f_no == 1)
		ft_error(7, all);
	tmp = ft_strdup(identifiers);
	free(tmp);
	tmp = ft_strtrim(&identifiers[2], " ");
	j = 0;
	while (tmp[j])
	{
		if (tmp[j] == ' ')
			ft_error(8, all);
		j++;
	}
	all->texture->no = tmp;
	if ((fd = open(all->texture->no, O_RDONLY)) == -1)
		ft_error(3, all);
	close(fd);
	all->flag2->f_no = 1;
	all->flag->pos_map++;
	all->flag->f_i++;
	ft_chech_txt_fotmat(all->texture->no, all);
}

void	ft_parse_so(char *identifiers, t_all *all)
{
	char	*tmp;
	int		j;
	int		fd;

	if (all->flag2->f_so == 1)
		ft_error(7, all);
	tmp = ft_strdup(identifiers);
	free(tmp);
	tmp = ft_strtrim(&identifiers[2], " ");
	j = 0;
	while (tmp[j])
	{
		if (tmp[j] == ' ')
			ft_error(8, all);
		j++;
	}
	all->texture->so = tmp;
	if ((fd = open(all->texture->so, O_RDONLY)) == -1)
		ft_error(3, all);
	close(fd);
	all->flag2->f_so = 1;
	all->flag->pos_map++;
	all->flag->f_i++;
	ft_chech_txt_fotmat(all->texture->so, all);
}

void	ft_parse_we(char *identifiers, t_all *all)
{
	char	*tmp;
	int		j;
	int		fd;

	if (all->flag2->f_we == 1)
		ft_error(7, all);
	tmp = ft_strdup(identifiers);
	free(tmp);
	tmp = ft_strtrim(&identifiers[2], " ");
	j = 0;
	while (tmp[j])
	{
		if (tmp[j] == ' ')
			ft_error(8, all);
		j++;
	}
	all->texture->we = tmp;
	if ((fd = open(all->texture->we, O_RDONLY)) == -1)
		ft_error(3, all);
	close(fd);
	all->flag2->f_we = 1;
	all->flag->pos_map++;
	all->flag->f_i++;
	ft_chech_txt_fotmat(all->texture->we, all);
}

void	ft_parse_ea(char *identifiers, t_all *all)
{
	char	*tmp;
	int		j;
	int		fd;

	if (all->flag2->f_ea == 1)
		ft_error(7, all);
	tmp = ft_strdup(identifiers);
	free(tmp);
	tmp = ft_strtrim(&identifiers[2], " ");
	j = 0;
	while (tmp[j])
	{
		if (tmp[j] == ' ')
			ft_error(8, all);
		j++;
	}
	all->texture->ea = tmp;
	if ((fd = open(all->texture->ea, O_RDONLY)) == -1)
		ft_error(3, all);
	close(fd);
	all->flag2->f_ea = 1;
	all->flag->pos_map++;
	all->flag->f_i++;
	ft_chech_txt_fotmat(all->texture->ea, all);
}
