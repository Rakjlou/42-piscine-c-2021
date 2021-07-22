/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:50:43 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:50:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

static char	*get_multiple_key(int index, int tab_size)
{
	int		i;
	int		zeros;
	char	*result;

	zeros = 3 * (tab_size - 1 - index);
	result = (char *)malloc(sizeof(char) * (zeros) + 2);
	result[0] = '1';
	i = 1;
	while (i < zeros + 1)
		result[i++] = '0';
	result[i] = '\0';
	return (result);
}

t_dict	*get_multiple_node(t_dict *dict, int i, int tab_size)
{
	char	*multiple_key;
	t_dict	*multiple;

	multiple_key = get_multiple_key(i, tab_size);
	multiple = ft_find_key(dict, multiple_key);
	free(multiple_key);
	return (multiple);
}
