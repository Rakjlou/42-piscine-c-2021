/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 20:38:15 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/16 20:38:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
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
