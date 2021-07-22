#include <stddef.h>

char	ft_get_last_char(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	while (str[i])
		i++;
	return (str[i - 1]);
}
