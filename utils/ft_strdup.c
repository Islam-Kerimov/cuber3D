/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:13:15 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:13:16 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(const char *s1)
{
	int		j;
	char	*new_s1;

	new_s1 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(*new_s1));
	if (new_s1 == NULL)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		new_s1[j] = s1[j];
		j++;
	}
	new_s1[j] = '\0';
	return (new_s1);
}
