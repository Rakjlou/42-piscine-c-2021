/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 04:34:43 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/11 04:34:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_FILE_H
# define FT_DISPLAY_FILE_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>

# define E_NO_FILE_GIVEN "File name missing."
# define E_TOO_MANY_ARGS "Too many arguments."
# define E_FILE_NON_READABLE "Cannot read file."
# define BUFFER_SIZE 32

void	ft_print(int fd, const char *str);
void	ft_print_endl(int fd, const char *str);
void	ft_print_error(const char *str);
void	ft_putbuf(const char *str, ssize_t size);
void	ft_putendl(const char *str);
int		ft_strlen(const char *str);
void	ft_display_file(int fd);

#endif
