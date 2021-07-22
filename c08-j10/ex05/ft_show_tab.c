/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 03:05:42 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/09 03:05:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

static void	ft_putendl(char *str)
{
	unsigned int	str_size;

	str_size = 0;
	while (str[str_size] != '\0')
		str_size++;
	write(1, str, str_size);
	write(1, "\n", 1);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr_positive(long nb)
{
	if (nb >= 10)
		ft_putnbr_positive(nb / 10);
	ft_putchar('0' + (nb % 10));
}

static void	ft_putnbr(int nb)
{
	long	printed;

	printed = nb;
	if (printed < 0)
	{
		ft_putchar('-');
		printed = -printed;
	}
	ft_putnbr_positive(printed);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (!(par->str == 0))
	{
		ft_putendl(par->str);
		ft_putnbr(par->size);
		ft_putchar('\n');
		ft_putendl(par->copy);
		par++;
	}
}
