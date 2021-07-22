/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 02:40:51 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/16 02:40:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cursor;

	cursor = begin_list;
	while (cursor)
	{
		if (cmp(cursor->data, data_ref) == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}
