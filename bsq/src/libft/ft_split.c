/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 00:06:49 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/09 00:06:51 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static int	in_charset(char c, char *charset)
{
	unsigned int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_items(char *str, char *charset)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (in_charset(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !in_charset(str[i], charset))
			i++;
	}
	return (count);
}

static void	fill_word(char **res, unsigned int idx, char *wrd, unsigned int len)
{
	unsigned int	i;

	i = 0;
	res[idx] = (char *)malloc(sizeof(char) * (len + 1));
	if (res[idx] == NULL)
		return ;
	while (i < len)
	{
		res[idx][i] = wrd[i];
		i++;
	}
	res[idx][i] = '\0';
}

static char	**fill_items(char **result, char *str, char *charset)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	word_size;
	unsigned int	word_index;

	i = 0;
	word_index = 0;
	while (str[i] != '\0')
	{
		while (in_charset(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			j = i;
			while (str[j] != '\0' && !in_charset(str[j], charset))
				j++;
			word_size = j - i;
			fill_word(result, word_index, str + i, word_size);
			word_index++;
			i = j;
		}
	}
	return (result);
}

char	**ft_split(char *str, char *charset, int *size)
{
	unsigned int	items_size;
	char			**result;

	items_size = count_items(str, charset);
	result = (char **)malloc(sizeof(char *) * (items_size + 1));
	*size = items_size;
	if (result == NULL)
		return (NULL);
	result = fill_items(result, str, charset);
	result[items_size] = 0;
	return (result);
}
