/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 23:39:21 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/16 23:39:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

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

static void	ft_list_merge_static(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cursor;

	if (*begin_list1 == NULL)
		*begin_list1 = begin_list2;
	else
	{
		cursor = ft_list_last_static(*begin_list1);
		cursor->next = begin_list2;
	}
}

static void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*cursor;
	void	*tmp;
	int		sorted;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		cursor = *begin_list;
		while (cursor && cursor->next)
		{
			if (cmp(cursor->data, cursor->next->data) > 0)
			{
				tmp = cursor->data;
				cursor->data = cursor->next->data;
				cursor->next->data = tmp;
				sorted = 0;
			}
			cursor = cursor->next;
		}
	}
}

/*
 * Yes, I am ashamed.
 */
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	ft_list_merge_static(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
