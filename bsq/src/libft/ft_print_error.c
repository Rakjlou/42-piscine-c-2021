#include "libft.h"
#include <unistd.h>

void	ft_print_error(const char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
}
