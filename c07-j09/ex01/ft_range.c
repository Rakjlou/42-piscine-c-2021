/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:00:06 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/08 20:00:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned int	result_size;
	unsigned int	i;
	int				*result;

	if (min >= max)
		return (NULL);
	result_size = max - min;
	i = 0;
	result = (int *)malloc(sizeof(int) * result_size);
	if (result == NULL)
		return (NULL);
	while (i < result_size)
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}
