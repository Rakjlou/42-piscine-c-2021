#include "bsq.h"
#include <time.h>
#include <stdio.h>

char	*get_line(t_bsq *bsq, int line)
{
	if (line >= bsq->lines_count)
		return (NULL);
	return (bsq->map[line]);
}

char	get_character_at(t_bsq *bsq, int x, int y)
{
	if (x >= bsq->lines_count || y >= bsq->lines_length)
		return (0);
	return (bsq->map[x][y]);
}

int	try_square(t_bsq *bsq, int x, int y)
{
	int		i;
	int		j;
	int		target_size;
	char	*line;

	i = -1;
	target_size = bsq->size + 1;
	while (++i < target_size)
	{
		j = -1;
		line = get_line(bsq, x + i) + y;
		while (++j < target_size)
		{
			if (line[j] == '\0' || line[j] == bsq->obstacle)
				return (j + 1);
		}
	}
	bsq->size = target_size;
	bsq->start_x = x;
	bsq->start_y = y;
	if (bsq->size + 1 + x <= bsq->lines_count
		&& bsq->size + 1 + y <= bsq->lines_length)
		try_square(bsq, x, y);
	return (1);
}

void	find_bsq(t_bsq *bsq)
{
	int		x;
	int		y;

	x = 0;
	while (x < bsq->lines_count - bsq->size)
	{
		y = 0;
		while (y < bsq->lines_length - bsq->size
			&& x < bsq->lines_count - bsq->size)
		{
			if (get_character_at(bsq, x, y + bsq->size) != bsq->obstacle
				|| bsq->size == 0)
				y += try_square(bsq, x, y);
			else
				y += bsq->size;
		}
		x++;
	}
}

void	solve(int fd)
{
	t_bsq	bsq;

	init_bsq(&bsq);
	if (!load_bsq(&bsq, fd))
		ft_print_error(E_MAP);
	else
	{
		find_bsq(&bsq);
		print_bsq(&bsq);
	}
	free_bsq(&bsq);
}
