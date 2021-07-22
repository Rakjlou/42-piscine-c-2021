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

#include "ft_display_file.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 1)
		ft_print_error(E_NO_FILE_GIVEN);
	else if (ac > 2)
		ft_print_error(E_TOO_MANY_ARGS);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
			ft_print_error(E_FILE_NON_READABLE);
		else
		{
			ft_display_file(fd);
			close(fd);
		}
	}
	return (0);
}
