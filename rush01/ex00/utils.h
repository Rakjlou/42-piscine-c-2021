/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:43:51 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/10 19:43:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	**ft_split(char *str, char *charset, unsigned int *split_size);
int		ft_atoi(char *str);
void	ft_putendl(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		*get_values_tab(int a, int b, int c, int d);

#endif
