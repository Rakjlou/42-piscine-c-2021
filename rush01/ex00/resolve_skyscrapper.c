/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_skyscrapper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:43:43 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/10 19:43:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"
#include "utils.h"

static void	set_comb_at_line(t_skyscraper *s, int *comb, unsigned int line)
{
	int	i;
	int	j;
	int	end;

	j = 0;
	i = line * LINE_LENGTH;
	end = i + LINE_LENGTH;
	while (i < end)
	{
		s->board[i] = comb[j];
		i++;
		j++;
	}
}

static int	comb_has_doubles(int *comb)
{
	int	i;
	int	j;

	i = 0;
	while (i < LINE_LENGTH)
	{
		j = i + 1;
		while (j < LINE_LENGTH)
		{
			if (comb[i] == comb[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_columns(t_skyscraper *s)
{
	int	comb[LINES_COUNT];
	int	column;
	int	up;
	int	down;

	column = 0;
	while (column < LINE_LENGTH)
	{
		get_views_for_col(s, column, &up, &down);
		comb[0] = s->board[0 + column];
		comb[1] = s->board[4 + column];
		comb[2] = s->board[8 + column];
		comb[3] = s->board[12 + column];
		if (get_comb_view_up(comb) != up
			|| get_comb_view_down(comb) != down || comb_has_doubles(comb))
		{
			return (0);
		}
		column++;
	}
	return (1);
}

static void	update_board(t_skyscraper *s)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = s->candidate_line1;
	j = s->candidate_line2;
	k = s->candidate_line3;
	l = s->candidate_line4;
	set_comb_at_line(s, s->candidates[LINE1][i], LINE1);
	set_comb_at_line(s, s->candidates[LINE2][j], LINE2);
	set_comb_at_line(s, s->candidates[LINE3][k], LINE3);
	set_comb_at_line(s, s->candidates[LINE4][l], LINE4);
}

int	resolve_skyscraper(t_skyscraper *s)
{
	s->candidate_line1 = 0;
	while (s->candidate_line1 < s->candidates_size[LINE1])
	{
		s->candidate_line2 = 0;
		while (s->candidate_line2 < s->candidates_size[LINE2])
		{
			s->candidate_line3 = 0;
			while (s->candidate_line3 < s->candidates_size[LINE3])
			{
				s->candidate_line4 = 0;
				while (s->candidate_line4 < s->candidates_size[LINE4])
				{
					update_board(s);
					if (check_columns(s))
						return (1);
					s->candidate_line4++;
				}
				s->candidate_line3++;
			}
			s->candidate_line2++;
		}
		s->candidate_line1++;
	}
	return (0);
}
