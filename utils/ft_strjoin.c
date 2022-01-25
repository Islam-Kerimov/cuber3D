/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:13:25 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:13:26 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	int		k;

	dst = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*dst));
	if (dst == NULL)
		return (NULL);
	k = 0;
	while (*s1 != '\0')
	{
		dst[k] = *s1++;
		k++;
	}
	while (*s2 != '\0')
	{
		dst[k] = *s2++;
		k++;
	}
	dst[k] = '\0';
	return (dst);
}
