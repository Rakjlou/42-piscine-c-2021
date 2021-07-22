/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:17:00 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/06 14:17:01 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_recursive_factorial_real(int nb, int depth, int factorial)
{
	if (nb < 0)
		return (0);
	else if (depth > nb)
		return (factorial);
	else
		return (ft_recursive_factorial_real(nb, depth + 1, factorial * depth));
}

int	ft_recursive_factorial(int nb)
{
	return (ft_recursive_factorial_real(nb, 1, 1));
}
