/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:30:26 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/02 22:30:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	ft_sswap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	sorted;
	int	i;
	int	elem_a;
	int	elem_b;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			elem_a = *(tab + i);
			elem_b = *(tab + i + 1);
			if (elem_b < elem_a)
			{
				ft_sswap(tab + i, tab + (i + 1));
				sorted = 0;
			}
			i++;
		}
	}
}
