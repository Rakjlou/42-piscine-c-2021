/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:25:09 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/16 22:25:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static int	ft_list_size_static(t_list *begin_list)
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

static t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*cursor;
	unsigned int	i;

	i = 0;
	cursor = begin_list;
	while (cursor)
	{
		if (i == nbr)
			return (cursor);
		cursor = cursor->next;
		i++;
	}
	return (NULL);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*list;
	int		i;
	int		j;
	void	*tmp;

	i = 0;
	list = begin_list;
	j = ft_list_size_static(begin_list) - 1;
	while (j > i)
	{
		tmp = ft_list_at(list, i)->data;
		ft_list_at(list, i)->data = ft_list_at(list, j)->data;
		ft_list_at(list, j)->data = tmp;
		i++;
		j--;
	}
}
