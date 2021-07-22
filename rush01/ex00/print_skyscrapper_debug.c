/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_skyscrapper_debug.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:43:41 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/10 19:43:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"
#include "utils.h"

static void	print_line_no_newline(t_skyscraper *s, unsigned int line)
{
	unsigned int	i;
	unsigned int	end;

	i = line * LINE_LENGTH;
	end = i + LINE_LENGTH;
	while (i < end)
	{
		ft_putnbr(s->board[i]);
		if (i < end - 1)
			ft_putstr(" ");
		i++;
	}
}

static void	print_top_view(t_skyscraper *s)
{
	ft_putstr("  ");
	ft_putnbr(s->views[VIEW_TOP_1]);
	ft_putstr(" ");
	ft_putnbr(s->views[VIEW_TOP_2]);
	ft_putstr(" ");
	ft_putnbr(s->views[VIEW_TOP_3]);
	ft_putstr(" ");
	ft_putnbr(s->views[VIEW_TOP_4]);
	ft_putendl("");
	ft_putendl("  | | | |");
}

static void	print_bottom_view(t_skyscraper *s)
{
	ft_putendl("  | | | |");
	ft_putstr("  ");
	ft_putnbr(s->views[VIEW_DOWN_1]);
	ft_putstr(" ");
	ft_putnbr(s->views[VIEW_DOWN_2]);
	ft_putstr(" ");
	ft_putnbr(s->views[VIEW_DOWN_3]);
	ft_putstr(" ");
	ft_putnbr(s->views[VIEW_DOWN_4]);
	ft_putendl("");
}

void	print_line_debug(t_skyscraper *s, unsigned int line)
{
	int	left;
	int	right;

	get_views_for_line(s, line, &left, &right);
	ft_putnbr(left);
	ft_putstr("-");
	print_line_no_newline(s, line);
	ft_putstr("-");
	ft_putnbr(right);
	ft_putendl("");
}

void	print_skyscraper_debug(t_skyscraper *s)
{
	int	line;
	int	j;

	line = 0;
	print_top_view(s);
	print_line_debug(s, 0);
	print_line_debug(s, 1);
	print_line_debug(s, 2);
	print_line_debug(s, 3);
	print_bottom_view(s);
	ft_putendl("---------");
	while (line < LINES_COUNT)
	{
		ft_putnbr(s->candidates_size[line]);
		ft_putstr(" candidates for line ");
		ft_putnbr(line);
		ft_putendl("");
		j = 0;
		while (s->candidates[line][j] != NULL)
		{
			print_comb(s->candidates[line][j]);
			j++;
		}
		line++;
	}
}
