/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:12:35 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/01 14:12:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int n)
{
	ft_putchar('0' + ((n / 10) % 10));
	ft_putchar('0' + (n % 10));
}

int		ft_pow(int base, int pow)
{
	int	result;

	result = base;
	while (pow > 1)
	{
		result = result * base;
		pow--;
	}
	return result;
}

void	ft_print_numbers(int *numbers, int max)
{
	int		i;

	i = 0;
	while (i < max)
	{
		printf("%02d ", numbers[i]);
		i++;
	}
	puts("");
}

void	ft_print_combn_recursive(int *numbers, int max, int depth)
{
	int	limit;
	int	current_number;

	printf()

	limit = ft_pow(10, max) - (max + depth);

	numbers[max - 1] = limit;










	current_number = numbers[depth];
	numbers[depth] = current_number + 1;
	ft_print_numbers(numbers, max);
	if (current_number < limit)
		ft_print_combn_recursive(numbers, max, depth + 1);
	/*int	limit;

	if (current < max)
	{
		numbers[current + 1] = numbers[current] + 1;
		ft_print_combn_recursive(numbers, max, current + 1);
		numbers[current] = numbers[current] + 1;
	}
	else
	{
		ft_print_numbers(numbers, max);
		limit = ft_pow(10, max) - (max + current);
		numbers[current] = numbers[current] + 1;
		printf("[0] %d [1] %d [current] %d CURRENT %d MAX %d\n", numbers[0], numbers[1], numbers[current], current, max);
		if (numbers[current] <= limit)
			ft_print_combn_recursive(numbers, max, current);
	}*/
	/*int	limit;
	ft_print_numbers(numbers, max);
	printf("Current %d\nMax %d\n------\n", current, max);

	limit = ft_pow(10, max) - (max + current);
	if (current == 0)
		numbers[0] = 0;
	else
		numbers[current] = numbers[current - 1] + 1;



	while (numbers[current] <= limit)
	{
		ft_print_numbers(numbers, max);
		numbers[current]++;
	}*/
}

void	ft_print_combn(int n)
{
	int numbers[10];

	if (n <= 0 || n > 10)
		return ;
	ft_print_combn_recursive(numbers, n, 0);
}
