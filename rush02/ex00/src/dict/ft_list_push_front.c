/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:50:15 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:50:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stddef.h>

void	ft_list_push_front(t_dict **begin_list, char *key, char *value)
{
	t_dict	*new;

	new = ft_create_elem(key, value);
	if (new == NULL)
		return ;
	if (*begin_list == NULL)
		new->next = NULL;
	else
		new->next = *begin_list;
	*begin_list = new;
}
