/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:55:51 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/04 19:55:51 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);

int	ft_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nega;
	int	output;

	nega = 1;
	i = 0;
	output = 0;
	if (str[i] == '-')
	{
		nega *= -1;
		i++;
	}
	while (ft_num(str[i]) == 1)
	{
		output = (output * 10) + (str[i] - 48);
		i++;
	}
	return (output * nega);
}

void	custom_rush(int x, int y, int type)
{
	if (type == 0)
		rush(x, y);
	else if (type == 1)
		rush01(x, y);
	else if (type == 2)
		rush02(x, y);
	else if (type == 3)
		rush03(x, y);
	else if (type == 4)
		rush04(x, y);
	else
		write(1, "Invalid rush type :(\n", 21);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		rush(5, 5);
	else if (argc == 3)
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	else if (argc == 4)
		custom_rush(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	return (0);
}
