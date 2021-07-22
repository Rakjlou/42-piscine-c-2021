/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:02:21 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/11 23:41:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"
#include "utils.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_skyscraper	s;

	if (argc != 2 || !init_skyscraper(&s, argv[1]) || !resolve_skyscraper(&s))
	{
		free_skyscraper(&s);
		write(2, ERROR_MSG, 5);
		write(2, "\n", 1);
		return (0);
	}
	print_skyscraper(&s);
	free_skyscraper(&s);
	return (0);
}
