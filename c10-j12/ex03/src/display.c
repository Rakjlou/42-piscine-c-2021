#include "ft_hexdump.h"

void	ft_print_address(t_hexdump *f)
{
	char	*hex;
	int		hex_size;
	int		padding;
	int		section_size;

	section_size = 7;
	if (f->option_c)
		section_size = 8;
	hex = ft_itoa_base(f->address, HEX_BASE, 16);
	hex_size = ft_strlen(hex);
	padding = section_size - hex_size;
	while (padding > 0)
	{
		ft_putstr("0");
		padding--;
	}
	ft_putstr(hex);
	free(hex);
}

void	ft_print_and_increment(const char *str, int *increment)
{
	ft_putstr(str);
	*increment += ft_strlen(str);
}

void	ft_print_buffer_hex(t_hexdump *f, const char *buffer, int section_size)
{
	ssize_t	i;
	int		written_size;
	char	*hex;
	int		hex_size;

	i = 0;
	written_size = 0;
	while (i < f->read_size)
	{
		hex = ft_itoa_base((unsigned char)buffer[i], HEX_BASE, 16);
		hex_size = ft_strlen(hex);
		if (hex_size == 1)
			ft_print_and_increment("0", &written_size);
		ft_print_and_increment(hex, &written_size);
		free(hex);
		if (f->option_c && i == 7 && i < f->read_size - 1)
			ft_print_and_increment("  ", &written_size);
		else if (i < f->read_size - 1)
			ft_print_and_increment(" ", &written_size);
		i++;
	}
	while (written_size++ < section_size)
		ft_putstr(" ");
}

void	ft_print_buffer_ascii(const char *buffer, ssize_t size)
{
	ssize_t	i;

	ft_putstr("|");
	i = 0;
	while (i < size)
	{
		if (buffer[i] >= 32 && buffer[i] <= 126)
			ft_putchar(buffer[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putstr("|");
}

void	ft_print_buffer(t_hexdump *f, char *buffer)
{
	ft_print_address(f);
	if (f->option_c)
		ft_putstr("  ");
	else
		ft_putstr(" ");
	if (f->option_c)
		ft_print_buffer_hex(f, buffer, 50);
	else
		ft_print_buffer_hex(f, buffer, 47);
	if (f->option_c)
		ft_print_buffer_ascii(buffer, f->read_size);
	ft_putendl("");
}
