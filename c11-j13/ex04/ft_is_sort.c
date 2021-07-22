/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:02:16 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/14 00:02:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_sort_regular(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_sort_rev(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	if (ft_is_sort_regular(tab, length, f) || ft_is_sort_rev(tab, length, f))
		return (1);
	return (0);
}
