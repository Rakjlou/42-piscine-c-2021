/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:33:04 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/16 22:33:05 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*before;
	t_list	*cursor;
	t_list	*new;

	before = NULL;
	new = ft_create_elem(data);
	cursor = *begin_list;
	while (cursor)
	{
		if (cmp(cursor->data, data) >= 0)
			break ;
		before = cursor;
		cursor = cursor->next;
	}
	if (before == NULL)
	{
		new->next = *begin_list;
		*begin_list = new;
	}
	else
	{
		new->next = before->next;
		before->next = new;
	}
}
