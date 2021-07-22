/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:52:35 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/17 13:52:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# define SMART 0

# include "dict.h"
# include "libft.h"

# define DICTIONARY_DEFAULT "resources/numbers.dict"
# define ERROR_MSG "Error\n"
# define DICT_ERROR_MSG "Dict Error\n"
# define BUFFER_SIZE 32

int		solve(t_dict *dict, char *number);
void	solve_triolet(t_dict *dict, char *triolet, char mult);
t_dict	*get_dictionary(char *dictionary_path);
char	*trim_num(char *number);
int		dict_has_mandatory_keys(t_dict *dict);
void	load_mandatory_keys(char **mandatory_keys);
t_dict	*get_multiple_node(t_dict *dict, int i, int tab_size);

#endif
