#include <unistd.h>

void	ft_putendl(char *str)
{
	unsigned int	str_size;

	str_size = 0;
	while (str[str_size] != '\0')
		str_size++;
	write(1, str, str_size);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	return (-1);
}

void	ft_swap(char **argv, int a, int b)
{
	char	*tmp;

	tmp = argv[a];
	argv[a] = argv[b];
	argv[b] = tmp;
}

void	ft_print_params(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
		ft_putendl(argv[i++]);
}

int	main(int argc, char **argv)
{
	int	i;
	int	sorted;

	if (argc > 2)
	{
		sorted = 0;
		while (sorted == 0)
		{
			i = 1;
			sorted = 1;
			while (i < argc - 1)
			{
				if (ft_strcmp(argv[i], argv[i + 1]) > 0)
				{
					ft_swap(argv, i, i + 1);
					sorted = 0;
				}
				i++;
			}
		}
		ft_print_params(argc, argv);
	}
	else if (argc == 2)
		ft_putendl(argv[1]);
	return (0);
}
