/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:13:42 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:13:43 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	s1_char = (unsigned char *)s1;
	s2_char = (unsigned char *)s2;
	i = 0;
	while ((i < n) && (s1_char[i] != '\0' || s2_char[i] != '\0'))
	{
		if (s1_char[i] == s2_char[i])
			i++;
		else if (s1_char[i] > s2_char[i])
			return (s1_char[i] - s2_char[i]);
		else if (s1_char[i] < s2_char[i])
			return (s1_char[i] - s2_char[i]);
	}
	return (0);
}
