/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 04:34:41 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/11 04:34:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_print(int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_print_endl(int fd, const char *str)
{
	ft_print(fd, str);
	ft_print(fd, "\n");
}

void	ft_print_error(const char *str)
{
	ft_print_endl(2, str);
}

void	ft_putbuf(const char *str, ssize_t size)
{
	write(1, str, size);
}

void	ft_putendl(const char *str)
{
	ft_print_endl(1, str);
}
