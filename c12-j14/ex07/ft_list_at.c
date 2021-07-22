/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:35:06 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/15 19:35:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*cursor;
	unsigned int	i;

	i = 0;
	cursor = begin_list;
	while (cursor != NULL)
	{
		if (i == nbr)
			return (cursor);
		cursor = cursor->next;
		i++;
	}
	return (NULL);
}
