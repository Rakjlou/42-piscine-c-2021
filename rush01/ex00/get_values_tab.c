/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:43:28 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/10 19:43:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*get_values_tab(int a, int b, int c, int d)
{
	int	*result;

	result = (int *)malloc(sizeof(int) * 4);
	if (result == NULL)
		return (NULL);
	result[0] = a;
	result[1] = b;
	result[2] = c;
	result[3] = d;
	return (result);
}
