/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:02:17 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/14 00:02:17 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr(int nb)
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
