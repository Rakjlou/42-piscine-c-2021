/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 04:34:38 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/11 04:34:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static void	ft_print_file_error(char *program_name, char *file)
{
	ft_print(2, basename(program_name));
	ft_print(2, ": ");
	ft_print(2, file);
	ft_print(2, ": ");
	ft_print_error(strerror(errno));
}

static void	ft_tail_all_args(int ac, char **av, int bytes_to_read, int p_file)
{
	int	i;
	int	succeeded;

	i = 3;
	succeeded = 0;
	while (i < ac)
	{
		if (!ft_tail(av[i], bytes_to_read, p_file, succeeded))
			ft_print_file_error(av[0], av[i]);
		else
			succeeded = 1;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	bytes_to_read;
	int	print_file_name;

	if (ac == 3 && ft_strcmp(av[1], "-c") == 0)
		ft_tail_fd(STDIN_FILENO, ft_atoi(av[2]));
	else if (ac > 3 && ft_strcmp(av[1], "-c") == 0)
	{
		print_file_name = 0;
		bytes_to_read = ft_atoi(av[2]);
		if (bytes_to_read == 0)
			return (0);
		else if (ac > 4)
			print_file_name = 1;
		if (bytes_to_read < 0)
			bytes_to_read = bytes_to_read * -1;
		ft_tail_all_args(ac, av, bytes_to_read, print_file_name);
	}
	return (0);
}
