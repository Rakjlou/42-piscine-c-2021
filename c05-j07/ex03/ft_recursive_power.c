/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:45:22 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/06 15:45:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_recursive_power_real(int nb, int power, int result, int depth)
{
	if (power < 0)
		return (0);
	else if ((nb == 0 && power == 0) || power == 0)
		return (1);
	else if (depth > power)
		return (result);
	else
		return (ft_recursive_power_real(nb, power, result * nb, depth + 1));
}

int	ft_recursive_power(int nb, int power)
{
	return (ft_recursive_power_real(nb, power, 1, 1));
}
