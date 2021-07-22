/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 03:22:44 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/15 03:22:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*cursor;
	int		i;

	i = 0;
	cursor = begin_list;
	while (cursor)
	{
		i++;
		cursor = cursor->next;
	}
	return (i);
}
