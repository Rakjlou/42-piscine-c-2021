#include "libft.h"

void	ft_putendl(const char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}
