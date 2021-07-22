/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 03:45:57 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/15 03:45:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
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
