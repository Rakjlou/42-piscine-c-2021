/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:43:19 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/10 19:43:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"
#include "utils.h"

int	get_comb_view_left(int *comb)
{
	unsigned int	i;
	int				max_seen;
	int				total_seen;

	i = 0;
	max_seen = 0;
	total_seen = 0;
	while (i < LINE_LENGTH)
	{
		if (comb[i] > max_seen)
		{
			max_seen = comb[i];
			total_seen++;
		}
		i++;
	}
	return (total_seen);
}

int	get_comb_view_right(int *comb)
{
	int	i;
	int	max_seen;
	int	total_seen;

	i = LINE_LENGTH - 1;
	max_seen = 0;
	total_seen = 0;
	while (i >= 0)
	{
		if (comb[i] > max_seen)
		{
			max_seen = comb[i];
			total_seen++;
		}
		i--;
	}
	return (total_seen);
}

int	get_comb_view_up(int *comb)
{
	return (get_comb_view_left(comb));
}

int	get_comb_view_down(int *comb)
{
	return (get_comb_view_right(comb));
}

void	print_comb(int *comb)
{
	int	i;

	i = 0;
	ft_putstr("[");
	while (i < LINE_LENGTH)
	{
		ft_putnbr(comb[i]);
		if (i < LINE_LENGTH - 1)
			ft_putstr(" ");
		i++;
	}
	ft_putendl("]");
}
