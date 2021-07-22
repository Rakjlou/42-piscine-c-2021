/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:31:51 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/17 23:31:53 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}					t_dict;

t_dict	*ft_create_elem(char *key, char *value);
t_dict	*ft_find_key(t_dict *list, char *key);
void	ft_list_push_front(t_dict **begin_list, char *key, char *value);
void	ft_dict_destroy(t_dict *dict);

#endif
