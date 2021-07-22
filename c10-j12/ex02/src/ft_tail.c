#include "ft_tail.h"

static void	ft_print_file_name(const char *str, int newl)
{
	if (newl > 0)
		ft_putendl("");
	ft_print(1, "==> ");
	ft_print(1, str);
	ft_putendl(" <==");
}

static char	*ft_get_str(int size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i <= size)
		str[i++] = '\0';
	return (str);
}

static void	add_char_to_buffer(char c, char *buffer, int buffer_size)
{
	int		i;
	char	old;
	char	swap;

	i = 0;
	swap = c;
	while (i < buffer_size)
	{
		old = buffer[i];
		buffer[i] = swap;
		swap = old;
		i++;
	}
}

int	ft_tail_fd(int fd, int bytes_to_read)
{
	char	*to_print;
	char	buffer[1];
	ssize_t	read_size;
	int		i;

	to_print = ft_get_str(bytes_to_read);
	if (to_print == NULL)
		return (0);
	while (1)
	{
		read_size = read(fd, buffer, 1);
		if (read_size == 0)
			break ;
		else
			add_char_to_buffer(buffer[0], to_print, bytes_to_read);
	}
	i = bytes_to_read - 1;
	while (i >= 0)
	{
		if (to_print[i] != '\0')
			write(1, to_print + i, 1);
		i--;
	}
	free(to_print);
	return (1);
}

int	ft_tail(char *file, int bytes_to_read, int print_file_name, int index)
{
	int	fd;
	int	res;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (0);
	if (print_file_name)
		ft_print_file_name(file, index);
	res = ft_tail_fd(fd, bytes_to_read);
	close(fd);
	return (res);
}
