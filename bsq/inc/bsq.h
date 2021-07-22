/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 00:12:44 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/21 00:12:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "libft.h"

# define E_MAP "map error\n"

typedef struct s_bsq
{
	char	**map;
	char	empty;
	char	obstacle;
	char	fill;
	int		lines_count;
	int		lines_length;
	int		size;
	int		start_x;
	int		start_y;
}	t_bsq;

int		load_bsq(t_bsq *bsq, int fd);
void	init_bsq(t_bsq *bsq);
void	free_bsq(t_bsq *bsq);
void	print_bsq_debug(t_bsq *bsq);
void	print_bsq(t_bsq *bsq);
char	*get_line(t_bsq *bsq, int line);
int		ft_check_first_line(t_bsq *bsq, char *first_line);
int		ft_check_map(t_bsq *bsq, char **map);
void	solve(int fd);

#endif
