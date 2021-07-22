/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 23:02:32 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/15 23:02:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

static void	ft_list_push_front_static(t_list **begin_list, t_list *new)
{
	if (new == NULL)
		return ;
	if (*begin_list == NULL)
		new->next = NULL;
	else
		new->next = *begin_list;
	*begin_list = new;
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*cursor;
	t_list	*before;
	t_list	*reverse;

	reverse = NULL;
	before = NULL;
	cursor = *begin_list;
	while (cursor)
	{
		before = cursor;
		cursor = cursor->next;
		ft_list_push_front_static(&reverse, before);
	}
	*begin_list = reverse;
}
