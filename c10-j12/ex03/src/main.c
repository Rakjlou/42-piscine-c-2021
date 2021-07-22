#include "ft_hexdump.h"

static void	ft_print_star(t_hexdump *f)
{
	f->star = 1;
	ft_putendl("*");
}

static void	ft_print_buffer_merci_la_norme(t_hexdump *f, char *buffer)
{
	f->star = 0;
	ft_print_buffer(f, buffer);
}

static void	ft_print_file_descriptor(t_hexdump *f)
{
	errno = 9;
	ft_print_file_error(f->program_name, f->files[f->total - 1]);
}

static void	ft_hexdump(t_hexdump *f)
{
	char	*buf;
	char	*obuf;

	obuf = NULL;
	while (1)
	{
		buf = get_next_buffer(f, &f->read_size);
		if (f->read_size == 0)
			break ;
		if (obuf != NULL
			&& ft_memcmp(buf, obuf, f->read_size) == 0 && f->star == 0)
			ft_print_star(f);
		else if (obuf == NULL || ft_memcmp(buf, obuf, f->read_size) != 0)
			ft_print_buffer_merci_la_norme(f, buf);
		f->address += f->read_size;
		if (obuf != NULL)
			free(obuf);
		obuf = buf;
	}
	if (f->total > 0 && f->opened_at_least_one == 0)
		ft_print_file_descriptor(f);
	if (f->address == 0)
		return ;
	ft_print_address(f);
	ft_putendl("");
}

int	main(int ac, char **av)
{
	t_hexdump	files;

	init_hexdump(&files, ac, av);
	ft_hexdump(&files);
}
