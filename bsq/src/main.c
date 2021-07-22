/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:54:14 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/20 23:54:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		i;
	int		fd;

	i = 1;
	if (ac <= 1)
	{
		solve(STDIN_FILENO);
		return (0);
	}
	else
	{
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd <= 0)
				ft_print_error(E_MAP);
			else
			{
				solve(fd);
				close(fd);
			}
			i++;
		}
	}
}
