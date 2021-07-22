/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:46:24 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/15 17:46:25 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static t_list	*ft_list_last_static(t_list *begin_list)
{
	t_list	*cursor;

	cursor = begin_list;
	while (cursor)
	{
		if (cursor->next == NULL)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;
	t_list	*new;

	new = ft_create_elem(data);
	new->next = NULL;
	if (*begin_list == NULL)
		*begin_list = new;
	else
	{
		last = ft_list_last_static(*begin_list);
		last->next = new;
	}
}
