/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydrate_combinations_candidates.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:43:30 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/10 19:43:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"
#include <stdlib.h>

static int	is_comb_ok_for_line(t_skyscraper *s, int *comb, unsigned int line)
{
	int	left;
	int	right;

	get_views_for_line(s, line, &left, &right);
	if (get_comb_view_left(comb) == left && get_comb_view_right(comb) == right)
		return (1);
	return (0);
}

static unsigned int	get_candidates_size(t_skyscraper *s, unsigned int line)
{
	unsigned int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (i < COMBINATIONS_SIZE)
	{
		if (is_comb_ok_for_line(s, s->combination[i], line))
			result++;
		i++;
	}
	return (result);
}

static void	hydrate_combination_candidates(t_skyscraper *s, unsigned int line)
{
	unsigned int	i;
	unsigned int	candidate_index;

	i = 0;
	candidate_index = 0;
	while (i < COMBINATIONS_SIZE)
	{
		if (is_comb_ok_for_line(s, s->combination[i], line))
		{
			s->candidates[line][candidate_index] = s->combination[i];
			candidate_index++;
		}
		i++;
	}
	s->candidates[line][candidate_index] = NULL;
}

static int	hydrate_candidates_for_line(t_skyscraper *s, unsigned int line)
{
	unsigned int	size;

	size = get_candidates_size(s, line) + 1;
	if (size <= 1)
		return (0);
	s->candidates[line] = (int **)malloc(sizeof(char *) * size);
	if (s->candidates[line] == NULL)
		return (0);
	hydrate_combination_candidates(s, line);
	s->candidates_size[line] = size - 1;
	return (1);
}

int	hydrate_combinations_candidates(t_skyscraper *s)
{
	unsigned int	i;

	i = 0;
	while (i < LINES_COUNT)
	{
		if (hydrate_candidates_for_line(s, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
