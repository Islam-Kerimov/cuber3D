/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_parsov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:07:04 by ctanton           #+#    #+#             */
/*   Updated: 2021/04/04 18:20:59 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_chech_txt_fotmat(char *s, t_all *all)
{
	if ((s[ft_strlen(s) - 3] >= 'a') && (s[ft_strlen(s) - 3] <= 'z') && \
			((s[ft_strlen(s) - 3] == 'x' && s[ft_strlen(s) - 2] == 'p' && \
			s[ft_strlen(s) - 1] == 'm') || (s[ft_strlen(s) - 3] == 'p' && \
			s[ft_strlen(s) - 2] == 'n' && s[ft_strlen(s) - 1] == 'g')))
		s = s + 0;
	else if ((s[ft_strlen(s) - 3] >= 'A') && (s[ft_strlen(s) - 3] <= 'Z') && \
			((s[ft_strlen(s) - 3] == 'X' && s[ft_strlen(s) - 2] == 'P' && \
			s[ft_strlen(s) - 1] == 'M') || (s[ft_strlen(s) - 3] == 'P' && \
			s[ft_strlen(s) - 2] == 'N' && s[ft_strlen(s) - 1] == 'G')))
		s = s + 0;
	else
		ft_error(8, all);
}

void	check_comma(char *identifiers, t_all *all)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (identifiers[i])
	{
		if (identifiers[i] == ',')
			f++;
		i++;
	}
	if (f != 2)
		ft_error(8, all);
}

void	ft_do(char **identifiers, t_all *all, int k)
{
	if (*identifiers[k] == 'R' && identifiers[k][1] == ' ')
		ft_parse_r(identifiers[k], all);
	else if (*identifiers[k] == 'C' && identifiers[k][1] == ' ')
		ft_parse_c(identifiers[k], all);
	else if (*identifiers[k] == 'F' && identifiers[k][1] == ' ')
		ft_parse_f(identifiers[k], all);
	else if (*identifiers[k] == 'S' && identifiers[k][1] == ' ')
		ft_parse_s(identifiers[k], all);
	else if (*identifiers[k] == 'N' && identifiers[k][1] == 'O' && \
			identifiers[k][2] == ' ')
		ft_parse_no(identifiers[k], all);
	else if (*identifiers[k] == 'S' && identifiers[k][1] == 'O' && \
			identifiers[k][2] == ' ')
		ft_parse_so(identifiers[k], all);
	else if (*identifiers[k] == 'W' && identifiers[k][1] == 'E' && \
			identifiers[k][2] == ' ')
		ft_parse_we(identifiers[k], all);
	else if (*identifiers[k] == 'E' && identifiers[k][1] == 'A' && \
			identifiers[k][2] == ' ')
		ft_parse_ea(identifiers[k], all);
	else if (*identifiers[k] == '\0' && all->flag->f_i < 8)
		all->flag->pos_map++;
	else if (all->flag->f_i < 8)
		ft_error(5, all);
}

void	ft_free(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i] != NULL)
		free(tmp[i++]);
	free(tmp);
}

char	**pars_parsov(char **identifiers, t_all *all)
{
	int k;
	int i;

	k = 0;
	while (identifiers[k])
	{
		if (*identifiers[k] == ' ' && all->flag->f_i != 8)
		{
			i = 0;
			while (identifiers[k][i] != '\0' && identifiers[k][i] != '1')
			{
				if (identifiers[k][i] == ' ')
					i++;
				else
					ft_error(5, all);
			}
			all->flag->pos_map++;
		}
		else
			ft_do(identifiers, all, k);
		k++;
	}
	return (identifiers);
}
