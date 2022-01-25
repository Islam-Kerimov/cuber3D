/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:07:30 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:07:31 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**trim_map(char **identifiers, t_all *all)
{
	int k;
	int i;

	k = 0;
	i = 0;
	while (identifiers[k] && i != 8)
	{
		if (identifiers[k][0] == 'S' || identifiers[k][0] == 'F' ||\
				identifiers[k][0] == 'C' || identifiers[k][0] == 'R' ||\
				identifiers[k][0] == 'N' || identifiers[k][0] == 'W' ||\
				identifiers[k][0] == 'E')
		{
			k++;
			i++;
		}
		else if (identifiers[k][0] == ' ' || identifiers[k][0] == '\0')
			k++;
	}
	while (!(ft_strchr(identifiers[k], '1')))
		k++;
	all->flag->pos_map = k;
	return (identifiers);
}
