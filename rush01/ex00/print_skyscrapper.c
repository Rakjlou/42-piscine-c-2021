/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_skyscrapper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:43:38 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/10 19:43:40 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"
#include "utils.h"
#include <stddef.h>

void	print_line(t_skyscraper *s, unsigned int line)
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
	ft_putendl("");
}

void	print_skyscraper(t_skyscraper *s)
{
	print_line(s, 0);
	print_line(s, 1);
	print_line(s, 2);
	print_line(s, 3);
}
