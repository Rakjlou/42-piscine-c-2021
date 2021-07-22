/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 04:14:38 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/21 04:14:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 512
# include <unistd.h>

int				get_next_line(int const fd, char **line);
int				ft_strlen(const char *str);
void			ft_putstr_fd(const char *str, int fd);
char			*ft_str_merge_buffer(char *str, char *buffer, int buffer_size);
char			*ft_strdup(char *src);
char			*ft_strstr(char *str, char *to_find);
char			**ft_split(char *str, char *charset, int *size);
int				ft_free_tab(char **tab);
char			ft_get_last_char(const char *str);
int				ft_char_is_printable(char c);
char			*ft_get_fd_contents(int fd, const char *read_error_msg);
void			ft_print_error(const char *str);
void			ft_putendl(const char *str);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strjoin_old(const char *s1, const char *s2);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strchr(const char *str, int c);
void			ft_magic_free(char *s1, char *s2, char **tab1, char **tab2);

#endif
