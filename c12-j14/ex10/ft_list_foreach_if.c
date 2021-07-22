/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 02:20:03 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/16 02:20:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
	void *data_ref, int (*cmp)())
{
	t_list	*cursor;

	cursor = begin_list;
	while (cursor)
	{
		if (cmp(cursor->data, data_ref) == 0)
			f(cursor->data);
		cursor = cursor->next;
	}
}
