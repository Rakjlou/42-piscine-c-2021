/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 04:34:36 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/11 04:34:37 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_display(int fd)
{
	char	buffer[32];
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, 32);
		if (bytes_read == 0)
			break ;
		ft_putbuf(buffer, bytes_read);
	}
}
