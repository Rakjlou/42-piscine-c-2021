/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:40:27 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/06 13:40:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define M_SIGN 0
#define M_WHITESPACE 1
#define M_FILL 2
#define M_NUMBER 3

static int	ft_char_is(unsigned char c, int mode, char *base)
{
	unsigned int	i;

	if (mode == M_SIGN)
		return (c == '-' || c == '+');
	else if (mode == M_WHITESPACE)
	{
		return (c == ' ' || c == '\t' || c == '\r' || c == '\n'
			|| c == '\v' || c == '\f');
	}
	else if (mode == M_FILL)
		return (ft_char_is(c, M_WHITESPACE, 0) || ft_char_is(c, M_SIGN, 0));
	else if (mode == M_NUMBER)
	{
		i = 0;
		while (base[i] != '\0')
		{
			if (c == base[i])
				return (1);
			i++;
		}
		return (0);
	}
	return (0);
}

static int	base_is_valid(char *base, unsigned int size, char *found)
{
	int	ci;

	ci = (int)*base;
	if (*base == '\0' && size > 1)
		return (1);
	else if (*base == '\0' || found[ci] == 1 || ft_char_is(*base, M_FILL, 0))
		return (0);
	else
	{
		found[ci] = 1;
		return (base_is_valid(base + 1, size + 1, found));
	}
}

static int	ft_num(unsigned char c, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_atoi_recursive(char *str, int number, char *base)
{
	int	base_size;

	if (!ft_char_is(*str, M_NUMBER, base))
		return (number);
	else
	{
		base_size = 0;
		while (base[base_size] != '\0')
			base_size++;
		return (ft_atoi_recursive(
				str + 1,
				(number * base_size) + ft_num(*str, base),
				base)
		);
	}
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	i;
	char			multiplier;
	char			found[255];

	i = 0;
	multiplier = 1;
	while (i < 255)
		found[i++] = 0;
	i = 0;
	if (!base_is_valid(base, 0, found))
		return (0);
	while (ft_char_is(str[i], M_WHITESPACE, 0))
		i++;
	while (ft_char_is(str[i], M_SIGN, 0))
	{
		if (str[i] == '-')
			multiplier = multiplier * -1;
		i++;
	}
	return (ft_atoi_recursive(str + i, 0, base) * multiplier);
}
