#include "ft_hexdump.h"

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_print_file_error(char *program_name, char *file)
{
	ft_print(2, basename(program_name));
	ft_print(2, ": ");
	ft_print(2, file);
	ft_print(2, ": ");
	ft_print_error(strerror(errno));
}
