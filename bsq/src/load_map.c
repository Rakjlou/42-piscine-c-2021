/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 02:54:34 by abiersoh          #+#    #+#             */
/*   Updated: 2021/07/21 02:55:22 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_getnblines(char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (i < ft_strlen(str) - 3)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		ret = (ret * 10) + str[i] - '0';
		i++;
	}
	return (ret);
}

int	ft_check_first_line(t_bsq *bsq, char *first_line)
{
	int		len;

	len = ft_strlen(first_line);
	if (len < 4)
		return (0);
	bsq->fill = first_line[len - 1];
	bsq->obstacle = first_line[len - 2];
	bsq->empty = first_line[len - 3];
	bsq->lines_count = ft_getnblines(first_line);
	if (bsq->lines_count == 0)
		return (0);
	if (bsq->fill == bsq->obstacle || bsq->fill == bsq->empty
		|| bsq->empty == bsq->obstacle)
		return (0);
	if (!ft_char_is_printable(bsq->obstacle)
		|| !ft_char_is_printable(bsq->fill)
		|| !ft_char_is_printable(bsq->empty))
		return (0);
	return (1);
}

int	ft_check_map(t_bsq *bsq, char **map)
{
	int	i;
	int	j;

	i = -1;
	bsq->lines_length = 0;
	while (map[++i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != bsq->obstacle && map[i][j] != bsq->empty)
				return (0);
			j++;
		}
		if (j != bsq->lines_length && i != 0)
			return (0);
		bsq->lines_length = j;
	}
	if (i != bsq->lines_count)
		return (0);
	return (1);
}
