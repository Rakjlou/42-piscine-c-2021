/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:41:07 by nsierra-          #+#    #+#             */
/*   Updated: 2021/06/30 20:41:13 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		ft_putchar(s[i++]);
}

void	ft_print_number(int n)
{
	ft_putchar('0' + ((n / 10) % 10));
	ft_putchar('0' + (n % 10));
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_print_number(a);
			ft_putchar(' ');
			ft_print_number(b);
			if (!(a == 98 && b == 99))
				ft_putstr(", ");
			b++;
		}
		a++;
	}
}
