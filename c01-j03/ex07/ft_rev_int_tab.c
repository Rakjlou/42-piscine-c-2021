/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:30:26 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/02 22:30:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_sswap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	ri;

	i = 0;
	ri = size - 1;
	while (i < size / 2)
	{
		if (i == ri)
			continue ;
		ft_sswap(tab + i, tab + ri);
		i++;
		ri--;
	}
}
