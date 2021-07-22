/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 05:31:21 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/11 05:31:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <sys/types.h>

# define BUFFER_SIZE 32

void	ft_print(int fd, const char *str);
void	ft_print_endl(int fd, const char *str);
void	ft_print_error(const char *str);
void	ft_putbuf(const char *str, ssize_t size);
void	ft_putendl(const char *str);
int		ft_strlen(const char *str);
void	ft_display(int fd);

#endif
