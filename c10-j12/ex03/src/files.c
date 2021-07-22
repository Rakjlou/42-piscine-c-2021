#include "ft_hexdump.h"

void	open_file(t_hexdump *f)
{
	f->fd = open(f->files[f->current], O_RDONLY);
	if (f->fd <= 0)
	{
		f->fd = -1;
		ft_print_file_error(f->program_name, f->files[f->current]);
		f->current += 1;
	}
}

int	close_and_recall(t_hexdump *f, char *c, int print_error)
{
	if (print_error)
		ft_print_file_error(f->program_name, f->files[f->current]);
	close(f->fd);
	f->current += 1;
	f->fd = -1;
	return (hydrate_next_char(f, c));
}

int	hydrate_next_char(t_hexdump *f, char *c)
{
	ssize_t	read_res;

	if (f->fd < 0 && f->current < f->total)
	{
		open_file(f);
		return (hydrate_next_char(f, c));
	}
	else if (f->fd >= 0)
	{
		f->opened_at_least_one = 1;
		read_res = read(f->fd, c, 1);
		if (read_res == 0)
			return (close_and_recall(f, c, 0));
		else if (read_res == -1)
			return (close_and_recall(f, c, 1));
		return (1);
	}
	else
	{
		close(f->fd);
		f->current += 1;
		f->fd = -1;
		return (0);
	}
}

char	*get_next_buffer(t_hexdump *f, int *size)
{
	char	*buffer;
	char	c;
	int		target_size;
	int		i;

	buffer = (char *)malloc(sizeof(char) * 16);
	i = 0;
	target_size = 16;
	while (i < 16)
	{
		if (hydrate_next_char(f, &c) == 0)
		{
			*size = i;
			return (buffer);
		}
		buffer[i++] = c;
	}
	*size = i;
	return (buffer);
}

void	init_hexdump(t_hexdump *files, int ac, char **av)
{
	files->program_name = basename(av[0]);
	files->address = 0;
	files->star = 0;
	files->read_size = 0;
	files->option_c = 0;
	files->current = 0;
	files->opened_at_least_one = 0;
	if (ac > 1 && ft_strcmp(av[1], "-C") == 0)
		files->option_c = 1;
	if ((files->option_c && ac == 2) || (!files->option_c && ac == 1))
	{
		files->files = NULL;
		files->current = -1;
		files->total = 0;
		files->fd = STDIN_FILENO;
	}
	else
	{
		files->files = av + (1 + files->option_c);
		files->total = ac - (1 + files->option_c);
		files->fd = -1;
	}
}
