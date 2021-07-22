int	ft_memcmp(void *a, void *b, int size)
{
	int		i;
	char	*abuf;
	char	*bbuf;

	i = 0;
	abuf = (char *)a;
	bbuf = (char *)b;
	while (i < size)
	{
		if (abuf[i] != bbuf[i])
			return (abuf[i] - bbuf[i]);
		i++;
	}
	return (0);
}
