/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:26:46 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/15 19:26:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*cursor;
	t_list	*to_free;

	cursor = begin_list;
	while (cursor)
	{
		to_free = cursor;
		cursor = cursor->next;
		free_fct(to_free->data);
		free(to_free);
	}
}
