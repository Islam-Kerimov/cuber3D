/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:12:30 by ctanton           #+#    #+#             */
/*   Updated: 2021/03/31 18:16:55 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *dst;

	dst = *lst;
	if (dst == NULL)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		while (dst->next != NULL)
			dst = dst->next;
		dst->next = new;
	}
}
