/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 05:31:21 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/11 05:31:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>

# define E_TOO_FEW_ARGS "Too few arguments. Please use -c NUMBER."

void	ft_print(int fd, const char *str);
void	ft_print_endl(int fd, const char *str);
void	ft_print_error(const char *str);
void	ft_putbuf(const char *str, ssize_t size);
void	ft_putendl(const char *str);
int		ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		ft_tail_fd(int fd, int bytes_to_read);
int		ft_tail(char *file, int bytes_to_read, int print_file_name, int newl);

#endif
