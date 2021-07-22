/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:02:13 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/04 17:02:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static void	ft_print_number_hex(unsigned char n)
{
	int		div;
	int		mod;
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\0", 2);
	while (1)
	{
		div = n / 16;
		mod = n % 16;
		if (div == 0)
		{
			write(1, hex + mod, 1);
			break ;
		}
		else
		{
			write(1, hex + div, 1);
		}
		n = mod;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] < 127)
			write(1, str + i, 1);
		else
			ft_print_number_hex(str[i]);
		i++;
	}
}
