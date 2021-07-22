/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:50:13 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:50:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stddef.h>

static int	ft_is_mkey(char *key, char **mandatory_keys)
{
	int	i;

	i = 0;
	while (mandatory_keys[i])
	{
		if (ft_strcmp(key, mandatory_keys[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

t_dict	*ft_find_key(t_dict *list, char *key)
{
	t_dict	*cursor;
	char	*m_keys[42];
	int		smart;

	smart = SMART;
	cursor = list;
	load_mandatory_keys(m_keys);
	while (cursor)
	{
		if (!smart && ft_strcmp(cursor->key, key) == 0
			&& ft_is_mkey(key, m_keys))
			return (cursor);
		else if (smart && ft_strcmp(cursor->key, key) == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}
