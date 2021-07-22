/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:50:11 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:51:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

static void	ft_dict_destroy_node(t_dict *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	ft_dict_destroy(t_dict *dict)
{
	t_dict	*cursor;
	t_dict	*before;

	cursor = dict;
	before = NULL;
	while (cursor)
	{
		if (before != NULL)
			ft_dict_destroy_node(before);
		before = cursor;
		cursor = cursor->next;
	}
	if (before != NULL)
		ft_dict_destroy_node(before);
}
