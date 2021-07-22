/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 03:06:01 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/16 03:06:03 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

static void	free_element(t_list *element, void (*free_fct)(void *))
{
	free_fct(element->data);
	free(element);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list	*cursor;
	t_list	*before;
	t_list	*to_free;

	before = NULL;
	cursor = *begin_list;
	while (cursor)
	{
		if (cmp(cursor->data, data_ref) == 0)
		{
			if (before == NULL)
				*begin_list = cursor->next;
			else
				before->next = cursor->next;
			to_free = cursor;
			cursor = cursor->next;
			free_element(to_free, free_fct);
		}
		else
		{
			before = cursor;
			cursor = cursor->next;
		}
	}
}
