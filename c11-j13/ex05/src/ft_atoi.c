/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:02:17 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/14 00:02:17 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

static int	is_number(int c)
{
	return (c >= '0' && c <= '9');
}

static int	is_whitespace(int c)
{
	return (c == ' ' || c == '\t' || c == '\r'
		|| c == '\n' || c == '\v' || c == '\f');
}

static int	ft_atoi_recursive(char *str, int number)
{
	if (!is_number(*str))
		return (number);
	else
		return (ft_atoi_recursive(str + 1, (number * 10) + (*str - 48)));
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	char			multiplier;

	i = 0;
	multiplier = 1;
	while (is_whitespace(str[i]))
		i++;
	while (is_sign(str[i]))
	{
		if (str[i] == '-')
			multiplier = multiplier * -1;
		i++;
	}
	return (ft_atoi_recursive(str + i, 0) * multiplier);
}
