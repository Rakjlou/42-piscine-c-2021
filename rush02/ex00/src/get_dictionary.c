/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dictionary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:50:16 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:52:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_dict	*free_the_norm(char **tab1, char **tab2, char *str, t_dict *ret)
{
	ft_destroy_tab(tab1);
	if (tab2 != NULL)
		ft_destroy_tab(tab2);
	if (str != NULL)
		free(str);
	return (ret);
}

static int	load_key_value(t_dict **dict, char *raw_key, char *raw_value)
{
	char	*tmp;
	char	*key;
	char	*value;
	int		ret;

	ret = 1;
	key = ft_trim_right(raw_key);
	value = ft_trim_left(raw_value);
	if (!ft_str_is_printable(value) || ft_strlen(value) == 0)
		ret = 0;
	tmp = key;
	key = ft_strdup(ft_sanitize_number(key));
	if (ft_strlen(key) == 0)
		ret = 0;
	free(tmp);
	ft_list_push_front(dict, key, value);
	return (ret);
}

static t_dict	*load_dictionary(char *raw_content)
{
	t_dict	*dict;
	char	**lines;
	char	**raw_kv;
	int		i;
	int		kv_size;

	i = 0;
	dict = NULL;
	lines = ft_split(raw_content, "\n", NULL);
	if (lines == NULL)
		return (NULL);
	while (lines[i])
	{
		raw_kv = ft_split(lines[i], ":", &kv_size);
		if (ft_count_char(lines[i], ':') != 1 || kv_size != 2
			|| !load_key_value(&dict, raw_kv[0], raw_kv[1]))
		{
			ft_dict_destroy(dict);
			return (free_the_norm(lines, raw_kv, raw_content, NULL));
		}
		ft_destroy_tab(raw_kv);
		i++;
	}
	free(raw_content);
	return (free_the_norm(lines, NULL, NULL, dict));
}

t_dict	*get_dictionary(char *dictionary_path)
{
	int		fd;
	char	*file_content;
	char	*to_free;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	file_content = ft_strdup("");
	fd = open(dictionary_path, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
		{
			free(file_content);
			return (NULL);
		}
		to_free = file_content;
		file_content = ft_str_merge_buffer(file_content, buffer, bytes_read);
		free(to_free);
	}
	return (load_dictionary(file_content));
}
