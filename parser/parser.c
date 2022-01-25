/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:53:51 by ctanton           #+#    #+#             */
/*   Updated: 2021/04/04 18:20:29 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_argv_file(t_all *all)
{
	int		fd;
	char	*tmp;

	if ((fd = open(all->flag->argv[1], O_RDONLY)) == -1)
		ft_error(3, all);
	if ((read(fd, NULL, 0)) < 0)
		ft_error(3, all);
	tmp = all->flag->argv[1];
	if (tmp[ft_strlen(all->flag->argv[1]) - 3] != 'c' && \
			tmp[ft_strlen(all->flag->argv[1]) - 2] != 'u' && \
			tmp[ft_strlen(all->flag->argv[1]) - 1] != 'b')
		ft_error(4, all);
	close(fd);
}

char	**ft_write_sceen(char **identifiers, t_all *all, size_t i)
{
	int		fd;
	int		j;
	char	*line;

	if ((fd = open(all->flag->argv[1], O_RDONLY)) == -1)
		ft_error(3, all);
	if (!(identifiers = (char **)malloc(i * sizeof(char *))))
		ft_error(14, all);
	j = 0;
	while (i > 0)
	{
		get_next_line(fd, &line);
		identifiers[j] = ft_strdup(line);
		free(line);
		j++;
		i--;
	}
	identifiers[j] = NULL;
	return (identifiers);
}

char	**ft_identifiers(char **identifiers, t_all *all)
{
	char	*line;
	t_list	*head;
	int		fd;
	size_t	i;
	char	*tmp;

	line = NULL;
	head = NULL;
	i = 0;
	tmp = all->flag->argv[1];
	if ((fd = open(tmp, O_RDONLY)) == -1)
		ft_error(3, all);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		i++;
	}
	free(line);
	i++;
	close(fd);
	identifiers = ft_write_sceen(identifiers, all, i);
	return (identifiers);
}

void	len_map(char **identifiers, t_all *all)
{
	int i;

	i = 0;
	while (identifiers[i])
		i++;
	all->flag->line_id = i;
}

char	**ft_read_map(t_all *all)
{
	char **map;
	char **identifiers;

	map = NULL;
	identifiers = NULL;
	check_argv_file(all);
	identifiers = ft_identifiers(identifiers, all);
	len_map(identifiers, all);
	identifiers = kill_spaces(identifiers);
	identifiers = pars_parsov(identifiers, all);
	identifiers = check_f_l_line(identifiers, all);
	identifiers = check_f_l_line_for_one_or_zero(identifiers, all);
	identifiers = check_zero(identifiers, all);
	identifiers = check_2(identifiers, all);
	identifiers = check_plr(identifiers, all);
	identifiers = check_one_plr(identifiers, all);
	identifiers = check_valid_simbol(identifiers, all);
	identifiers = trim_map(identifiers, all);
	map = ft_cat_map(map, all, identifiers);
	ft_init_player(map, all);
	ft_init_sprites(map, all);
	return (map);
}
