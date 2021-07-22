/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:50:40 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:52:36 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

static int	fill_triolet(char **result, int number_index, char *number, int i)
{
	result[number_index] = ft_strndup(number + i, 3);
	return (i + 3);
}

static char	**ft_cut_number(char *number, int *tab_size)
{
	int		i;
	int		number_index;
	int		result_size;
	int		result_size_mod;
	char	**result;

	i = 0;
	number_index = 0;
	result_size = ft_strlen(number) / 3;
	result_size_mod = ft_strlen(number) % 3;
	if (result_size_mod != 0)
		result_size++;
	result = (char **)malloc(sizeof(char *) * (result_size + 1));
	*tab_size = result_size;
	if (result_size_mod > 0)
	{
		result[number_index++] = ft_strndup(number, result_size_mod);
		i = result_size_mod;
	}
	while (number_index < result_size)
		i = fill_triolet(result, number_index++, number, i);
	result[number_index] = NULL;
	return (result);
}

static int	is_just_zero(t_dict *dict, char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (number[i] != '0')
			return (0);
		i++;
	}
	ft_magic_print(ft_find_key(dict, "0")->value);
	return (1);
}

int	solve(t_dict *dict, char *number)
{
	int		i;
	int		tab_size;
	char	**tab;
	t_dict	*mult;

	number = trim_num(number);
	if (is_just_zero(dict, number))
		return (1);
	i = 0;
	tab = ft_cut_number(number, &tab_size);
	while (tab[i])
	{
		if (i < tab_size - 1)
		{
			mult = get_multiple_node(dict, i, tab_size);
			if (mult == NULL && ft_destroy_tab(tab))
				return (0);
		}
		solve_triolet(dict, tab[i], '1');
		if (i < tab_size - 1 && mult != NULL && ft_strlen(trim_num(tab[i])) > 0)
			ft_magic_print(mult->value);
		i++;
	}
	ft_destroy_tab(tab);
	return (1);
}
