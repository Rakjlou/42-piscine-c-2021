/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 00:02:18 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/14 00:02:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int	get_operator_index(char *str)
{
	int		i;
	char	o;
	char	*operators;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i != 1)
		return (-1);
	i = 0;
	o = str[0];
	operators = "+-/*%";
	while (operators[i] != '\0')
	{
		if (operators[i] == o)
			return (i);
		i++;
	}
	return (-1);
}

int	check_div_by_zero(int op_index, int number)
{
	if (op_index == 2 && number == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	else if (op_index == 4 && number == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	(*fun[5])(int a, int b);
	int	operator_index;
	int	a;
	int	b;

	if (ac != 4)
		return (0);
	fun[0] = sum;
	fun[1] = substract;
	fun[2] = divide;
	fun[3] = multiply;
	fun[4] = modulo;
	operator_index = get_operator_index(av[2]);
	if (operator_index == -1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	if (check_div_by_zero(operator_index, b))
	{
		ft_putnbr((*fun[operator_index])(a, b));
		write(1, "\n", 1);
	}
}
