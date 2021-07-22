/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 04:00:25 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/07 04:00:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1 || ((nb % 2) == 0 && nb > 2))
		return (0);
	i = 3;
	while (i < (nb / 2))
	{
		if (nb % i == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		else if (nb > 2 && (nb % 2) == 0)
		{
			nb++;
			continue ;
		}
		nb++;
	}
	return (nb);
}
