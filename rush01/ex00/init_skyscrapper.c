/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skyscrapper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:43:33 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/10 19:43:35 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"
#include "utils.h"
#include <stddef.h>
#include <stdlib.h>

static void	hydrate_combination(t_skyscraper *s)
{
	s->combination[0] = get_values_tab(1, 2, 3, 4);
	s->combination[1] = get_values_tab(1, 2, 4, 3);
	s->combination[2] = get_values_tab(1, 3, 2, 4);
	s->combination[3] = get_values_tab(1, 3, 4, 2);
	s->combination[4] = get_values_tab(1, 4, 3, 2);
	s->combination[5] = get_values_tab(1, 4, 2, 3);
	s->combination[6] = get_values_tab(2, 1, 3, 4);
	s->combination[7] = get_values_tab(2, 1, 4, 3);
	s->combination[8] = get_values_tab(2, 3, 1, 4);
	s->combination[9] = get_values_tab(2, 3, 4, 1);
	s->combination[10] = get_values_tab(2, 4, 3, 1);
	s->combination[11] = get_values_tab(2, 4, 1, 3);
	s->combination[12] = get_values_tab(3, 1, 2, 4);
	s->combination[13] = get_values_tab(3, 1, 4, 2);
	s->combination[14] = get_values_tab(3, 2, 1, 4);
	s->combination[15] = get_values_tab(3, 2, 4, 1);
	s->combination[16] = get_values_tab(3, 4, 2, 1);
	s->combination[17] = get_values_tab(3, 4, 1, 2);
	s->combination[18] = get_values_tab(4, 1, 2, 3);
	s->combination[19] = get_values_tab(4, 1, 3, 2);
	s->combination[20] = get_values_tab(4, 2, 3, 1);
	s->combination[21] = get_values_tab(4, 2, 1, 3);
	s->combination[22] = get_values_tab(4, 3, 2, 1);
	s->combination[23] = get_values_tab(4, 3, 1, 2);
}

static void	hydrate_int_tab(int *tab, unsigned int size, int value)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = value;
		i++;
	}
}

/* TODO: Simpilifier la logique pour eviter d'utiliser split */
static int	hydrate_views(t_skyscraper *s, char *raw_views)
{
	char			**raw_views_split;
	unsigned int	split_size;
	unsigned int	i;

	i = 0;
	raw_views_split = ft_split(raw_views, " \t\v\n\r\f", &split_size);
	if (raw_views_split == NULL || split_size != VIEWS_SIZE)
	{
		while (i < split_size)
			free(raw_views_split[i++]);
		if (raw_views_split != NULL)
			free(raw_views_split);
		return (0);
	}
	while (i < VIEWS_SIZE)
	{
		s->views[i] = ft_atoi(raw_views_split[i]);
		if (s->views[i] < 1 || s->views[i] > 4)
			return (0);
		free(raw_views_split[i]);
		i++;
	}
	free(raw_views_split);
	return (1);
}

static void	hydrate_candidate_indexes(t_skyscraper *s)
{
	int	i;

	i = 0;
	s->candidate_line1 = 0;
	s->candidate_line2 = 0;
	s->candidate_line3 = 0;
	s->candidate_line4 = 0;
	while (i < LINES_COUNT)
		s->candidates[i++] = NULL;
}

int	init_skyscraper(t_skyscraper *s, char *raw_views)
{
	hydrate_int_tab(s->board, BOARD_SIZE, 0);
	hydrate_combination(s);
	hydrate_candidate_indexes(s);
	if (!hydrate_views(s, raw_views) || !hydrate_combinations_candidates(s))
		return (0);
	return (1);
}
