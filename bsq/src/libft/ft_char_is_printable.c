int	ft_char_is_printable(char c)
{
	if (c < 32 || c == 127)
		return (0);
	return (1);
}
