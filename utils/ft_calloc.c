/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:12:18 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:12:19 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;
	size_t	i;

	new = malloc(count * size);
	if (new == NULL)
		return (new);
	i = 0;
	while (i < count * size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
