/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:08:04 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:08:05 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*kill_spaces2(char *identifiers)
{
	char *tmp;
	char *tmp_free;

	if ((tmp = ft_strchr(identifiers, 'R')))
		tmp_free = ft_strdup(tmp);
	else if ((tmp = ft_strchr(identifiers, 'F')))
		tmp_free = ft_strdup(tmp);
	else if ((tmp = ft_strchr(identifiers, 'C')))
		tmp_free = ft_strdup(tmp);
	else if ((tmp = ft_strchr(identifiers, 'S')) && tmp[1] == ' ')
		tmp_free = ft_strdup(tmp);
	else if ((tmp = ft_strchr(identifiers, 'N')) && tmp[1] == 'O')
		tmp_free = ft_strdup(tmp);
	else if ((tmp = ft_strchr(identifiers, 'S')) && tmp[1] == 'O')
		tmp_free = ft_strdup(tmp);
	else if ((tmp = ft_strchr(identifiers, 'W')) && tmp[1] == 'E')
		tmp_free = ft_strdup(tmp);
	else if ((tmp = ft_strchr(identifiers, 'E')) && tmp[1] == 'A')
		tmp_free = ft_strdup(tmp);
	else
		return (identifiers);
	free(identifiers);
	identifiers = tmp_free;
	return (identifiers);
}

char	**kill_spaces(char **identifiers)
{
	int		k;

	k = 0;
	while (identifiers[k])
	{
		if (*identifiers[k] == ' ')
		{
			identifiers[k] = kill_spaces2(identifiers[k]);
			k++;
		}
		else
			k++;
	}
	return (identifiers);
}
