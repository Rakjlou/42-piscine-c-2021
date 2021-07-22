#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# define BUFFER_SIZE 16
# define HEX_SECTION_SIZE 50
# define HEX_BASE "0123456789abcdef"

# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_hexdump
{
	unsigned int	address;
	char			**files;
	char			*program_name;
	int				current;
	int				total;
	int				fd;
	int				star;
	int				option_c;
	int				read_size;
	int				opened_at_least_one;
}	t_hexdump;

void	ft_print(int fd, const char *str);
void	ft_print_endl(int fd, const char *str);
void	ft_print_error(const char *str);
void	ft_putbuf(const char *str, ssize_t size);
void	ft_putendl(const char *str);
int		ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strdup(char *src);
void	ft_putstr(const char *str);
void	ft_putchar(const char c);
void	ft_print_file_error(char *program_name, char *file);
void	init_hexdump(t_hexdump *files, int ac, char **av);
char	*ft_itoa_base(int num, char *base, unsigned int base_size);
int		hydrate_next_char(t_hexdump *f, char *c);
char	*get_next_buffer(t_hexdump *f, int *size);
void	ft_print_buffer(t_hexdump *f, char *buffer);
void	ft_print_address(t_hexdump *f);
int		ft_memcmp(void *a, void *b, int size);

#endif
