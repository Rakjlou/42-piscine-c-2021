/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_triolet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:50:41 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:52:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

static char	*get_mult_value(t_dict *dict, char mult)
{
	char	str[2];

	str[0] = mult;
	str[1] = '\0';
	return (ft_find_key(dict, str)->value);
}

static char	*simplify_triolet(char *triolet, char *multiplier)
{
	int		i;
	char	*res;

	i = ft_strlen(triolet) - 1;
	res = ft_strdup(triolet);
	while (i > 0)
	{
		if (triolet[i] != '0')
			break ;
		i--;
	}
	if (i == 0)
	{
		*multiplier = res[i];
		res[i] = '1';
		return (res);
	}
	res[i] = '0';
	return (res);
}

char	*trim_num(char *number)
{
	int	i;

	i = 0;
	while (number[i] && number[i] == '0')
		i++;
	return (number + i);
}

void	solve_triolet(t_dict *dict, char *triolet, char mult)
{
	t_dict	*word;
	char	*s_triolet;

	s_triolet = trim_num(triolet);
	if (*s_triolet == '\0')
		return ;
	while (1)
	{
		word = ft_find_key(dict, s_triolet);
		if (word == NULL)
			s_triolet = simplify_triolet(s_triolet, &mult);
		else
		{
			if (ft_strlen(s_triolet) == 3)
				ft_magic_print2(get_mult_value(dict, mult), word->value);
			else
				ft_magic_print(word->value);
			if (ft_strlen(word->key) == 2 && word->key[1] != '0')
				solve_triolet(dict, trim_num(triolet) + 2, mult);
			else
				solve_triolet(dict, trim_num(triolet) + 1, mult);
			break ;
		}
		free(s_triolet);
	}
}
