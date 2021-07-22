#include <stdlib.h>

char	*ft_itoa_base(int num, char *base, unsigned int base_size)
{
	char	buffer[32];
	char	*result;
	int		i;
	int		j;
	long	number;

	i = 0;
	j = 0;
	number = num;
	if (number < 0)
		number = number * -1;
	while (1)
	{
		buffer[i++] = base[number % base_size];
		if (number / base_size == 0)
			break ;
		number = number / base_size;
	}
	result = (char *)malloc((sizeof(char) * i) + 2);
	if (num < 0)
		result[j++] = '-';
	while (i > 0)
		result[j++] = buffer[--i];
	result[j] = '\0';
	return (result);
}
