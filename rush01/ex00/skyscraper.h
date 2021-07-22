/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:43:49 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/10 19:43:50 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPER_H
# define SKYSCRAPER_H

# define VIEWS_SIZE 16
# define BOARD_SIZE 16
# define LINE_LENGTH 4
# define LINES_COUNT 4
# define COMBINATIONS_SIZE 24
# define LINE1 0
# define LINE2 1
# define LINE3 2
# define LINE4 3
# define VIEW_TOP_1 0
# define VIEW_TOP_2 1
# define VIEW_TOP_3 2
# define VIEW_TOP_4 3
# define VIEW_DOWN_1 4
# define VIEW_DOWN_2 5
# define VIEW_DOWN_3 6
# define VIEW_DOWN_4 7
# define VIEW_LEFT_1 8
# define VIEW_LEFT_2 9
# define VIEW_LEFT_3 10
# define VIEW_LEFT_4 11
# define VIEW_RIGHT_1 12
# define VIEW_RIGHT_2 13
# define VIEW_RIGHT_3 14
# define VIEW_RIGHT_4 15
# define ERROR_MSG "Error"

# include <stdio.h>

typedef struct s_skyscraper
{
	int	views[VIEWS_SIZE];
	int	board[BOARD_SIZE];
	int	*combination[COMBINATIONS_SIZE];
	int	**candidates[LINES_COUNT];
	int	candidates_size[LINES_COUNT];
	int	candidate_line1;
	int	candidate_line2;
	int	candidate_line3;
	int	candidate_line4;
}	t_skyscraper;

int		init_skyscraper(t_skyscraper *s, char *raw_views);
int		hydrate_combinations_candidates(t_skyscraper *s);
void	get_views_for_line(t_skyscraper *s, unsigned int line, int *l, int *r);
void	get_views_for_col(t_skyscraper *s, unsigned int line, int *u, int *d);
void	print_skyscraper(t_skyscraper *s);
void	print_line(t_skyscraper *s, unsigned int line);
void	print_skyscraper_debug(t_skyscraper *s);
void	print_line_debug(t_skyscraper *s, unsigned int line);
int		resolve_skyscraper(t_skyscraper *s);
void	free_skyscraper(t_skyscraper *s);
void	print_comb(int *comb);
int		get_comb_view_left(int *comb);
int		get_comb_view_up(int *comb);
int		get_comb_view_right(int *comb);
int		get_comb_view_down(int *comb);

#endif
