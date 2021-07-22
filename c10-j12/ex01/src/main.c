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

#include "ft_cat.h"

static int	ft_cat_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (0);
	ft_display(fd);
	close(fd);
	return (1);
}

static int	ft_dispatch_action(const char *str)
{
	if (str[0] == '-' && str[1] == '\0')
		ft_display(STDIN_FILENO);
	else
		return (ft_cat_file(str));
	return (1);
}

static void	ft_print_file_error(char *program_name, char *file)
{
	ft_print(2, basename(program_name));
	ft_print(2, ": ");
	ft_print(2, file);
	ft_print(2, ": ");
	ft_print_error(strerror(errno));
}

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
		ft_display(STDIN_FILENO);
	else
	{
		i = 1;
		while (i < ac)
		{
			if (!ft_dispatch_action(av[i]))
				ft_print_file_error(av[0], av[i]);
			i++;
		}
	}
	return (0);
}
