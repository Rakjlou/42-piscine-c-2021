#include "bsq.h"
#include <stdlib.h>
#include <stdio.h>

int	load_bsq2(t_bsq *bsq, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	bsq->map = (char **)malloc(sizeof(char *) * (bsq->lines_count + 1));
	if (bsq->map == NULL)
		return (0);
	while (i < bsq->lines_count && get_next_line(fd, &line))
	{
		bsq->map[j++] = ft_strdup(line);
		i++;
		free(line);
		line = NULL;
	}
	bsq->map[j] = NULL;
	if (j != bsq->lines_count || get_next_line(fd, &line) > 0
		|| !ft_check_map(bsq, bsq->map))
	{
		ft_magic_free(line, NULL, bsq->map, NULL);
		bsq->map = NULL;
		return (0);
	}
	return (1);
}

int	load_bsq(t_bsq *bsq, int fd)
{
	char	*line;
	int		res;

	get_next_line(fd, &line);
	if (!ft_check_first_line(bsq, line))
	{
		free(line);
		return (0);
	}
	free(line);
	res = load_bsq2(bsq, fd);
	return (res);
}

void	print_bsq(t_bsq *bsq)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < bsq->size)
	{
		j = 0;
		line = get_line(bsq, bsq->start_x + i) + bsq->start_y;
		while (j < bsq->size)
			line[j++] = bsq->fill;
		i++;
	}
	i = 0;
	while (i < bsq->lines_count)
	{
		ft_putendl(get_line(bsq, i));
		i++;
	}
}

void	init_bsq(t_bsq *bsq)
{
	bsq->map = NULL;
	bsq->empty = 0;
	bsq->obstacle = 0;
	bsq->fill = 0;
	bsq->lines_count = 0;
	bsq->lines_length = 0;
	bsq->size = 0;
	bsq->start_x = 0;
	bsq->start_y = 0;
}

void	free_bsq(t_bsq *bsq)
{
	if (bsq->map != NULL)
		ft_free_tab(bsq->map);
}
