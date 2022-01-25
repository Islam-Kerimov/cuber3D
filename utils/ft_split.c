/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:13:00 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:13:02 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_how_many_arrays(char const *s, char c)
{
	int	i;
	int	sum_str;

	i = 0;
	sum_str = 0;
	if (s[i] == 0)
		return (0);
	if (s[i] == c)
		while (s[i] == c && s[i] != '\0')
			i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] != '\0')
		{
			sum_str++;
			while (s[i] == c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				break ;
		}
		i++;
	}
	if (s[i - 1] != c)
		sum_str++;
	return (sum_str);
}

int			ft_len_word(const char *s, char c)
{
	int			i;
	int			len;
	const char	*tmp;

	i = 0;
	len = 0;
	tmp = s;
	while (tmp[i] == c)
		i++;
	while (tmp[i] != c && tmp[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**free_dst(char **s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**dst;
	int		arrays;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	arrays = ft_how_many_arrays(s, c);
	if (!(dst = (char **)malloc((arrays + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < arrays)
	{
		j = 0;
		while (*s == c)
			s++;
		if (!(dst[i] = (char *)malloc((ft_len_word(s, c) + 1) * sizeof(char))))
			return (free_dst(dst));
		while (*s != c && *s != '\0')
			dst[i][j++] = *s++;
		dst[i++][j] = '\0';
	}
	dst[i] = NULL;
	return (dst);
}
