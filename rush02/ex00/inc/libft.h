/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:31:45 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/17 23:31:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_destroy_tab(char **tab);
char	*ft_strdup(char *src);
char	*ft_strndup(char *src, int len);
char	*ft_str_merge_buffer(char *str, char *buffer, int buffer_size);
char	**ft_split(char *str, char *charset, int *size);
int		ft_char_is_space(char c);
void	ft_magic_print(char *str);
void	ft_magic_print2(char *str, char *str2);
char	*ft_trim(char *str);
char	*ft_trim_left(char *str);
char	*ft_trim_right(char *str);
int		ft_str_is_printable(char *str);
int		ft_count_char(char *str, char c);
char	*ft_sanitize_number(char *number);

#endif
