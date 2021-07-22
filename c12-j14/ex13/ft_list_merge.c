/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 04:11:29 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/16 04:11:30 by nsierra-         ###   ########.fr       */
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

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
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
