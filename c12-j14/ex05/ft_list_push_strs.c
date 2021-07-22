/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:05:33 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/15 19:05:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

static void	ft_list_push_front_static(t_list **begin_list, void *data)
{
	t_list	*new;

	new = ft_create_elem(data);
	if (new == NULL)
		return ;
	if (*begin_list == NULL)
		new->next = NULL;
	else
		new->next = *begin_list;
	*begin_list = new;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	int		i;

	i = 0;
	list = NULL;
	while (i < size)
		ft_list_push_front_static(&list, strs[i++]);
	return (list);
}
