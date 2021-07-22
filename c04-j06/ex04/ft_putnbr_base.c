/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:40:20 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/06 13:40:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	base_is_valid(char *base, unsigned int size, char *found)
{
	int	ci;

	ci = (int)*base;
	if (*base == '\0' && size > 1)
		return (1);
	else if (*base == '\0' || found[ci] == 1 || *base == '-' || *base == '+')
		return (0);
	else
	{
		found[ci] = 1;
		return (base_is_valid(base + 1, size + 1, found));
	}
}

static unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_putnbr_base_real(long num, char *base, unsigned int base_size)
{
	if (num < base_size)
	{
		write(1, base + (num % base_size), 1);
		return ;
	}
	ft_putnbr_base_real(num / base_size, base, base_size);
	write(1, base + (num % base_size), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	long			number;
	char			found[255];

	i = 0;
	while (i < 255)
		found[i++] = 0;
	if (!base_is_valid(base, 0, found))
		return ;
	number = nbr;
	if (number < 0)
	{
		write(1, "-", 1);
		number = number * -1;
	}
	ft_putnbr_base_real(number, base, ft_strlen(base));
}
