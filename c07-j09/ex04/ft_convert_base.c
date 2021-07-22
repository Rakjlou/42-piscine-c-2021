/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:00:10 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/08 20:00:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static unsigned int	get_size_base_and_validate(char *base)
{
	unsigned int	i;
	unsigned int	j;
	char			c;

	i = 0;
	while (base[i] != '\0')
	{
		c = base[i];
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == c)
				return (0);
			j++;
		}
		if (c == '-' || c == '+' || c == ' ' || (c >= 9 && c <= 13))
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

static int	get_number_by_base_char(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_atoi_base(char *str, char *base, unsigned int base_size)
{
	unsigned int	i;
	int				number;
	char			multiplier;

	i = 0;
	number = 0;
	multiplier = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			multiplier = multiplier * -1;
		i++;
	}
	while (get_number_by_base_char(str[i], base) != -1)
	{
		number = (number * base_size) + get_number_by_base_char(str[i], base);
		i++;
	}
	return (number * multiplier);
}

static char	*ft_itoa_base(int num, char *base, unsigned int base_size)
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	base_from_size;
	unsigned int	base_to_size;
	int				number;

	(void)nbr;
	base_from_size = get_size_base_and_validate(base_from);
	base_to_size = get_size_base_and_validate(base_to);
	if (!base_from_size || !base_to_size)
		return (NULL);
	number = ft_atoi_base(nbr, base_from, base_from_size);
	return (ft_itoa_base(number, base_to, base_to_size));
}
