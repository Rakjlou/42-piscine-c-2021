/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_skyscraper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:43:22 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/10 19:43:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"
#include <stdlib.h>

void	free_skyscraper(t_skyscraper *s)
{
	int	i;

	i = 0;
	while (i < COMBINATIONS_SIZE)
		free(s->combination[i++]);
	i = 0;
	while (i < LINES_COUNT)
	{
		if (s->candidates[i] != NULL)
			free(s->candidates[i]);
		i++;
	}
}
