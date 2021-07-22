/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:00:09 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/08 20:00:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

static char	*ft_strncat_buffer(char *dest, char *buffer, int buffer_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (j < buffer_size)
	{
		dest[i + j] = buffer[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_str_merge_buffer(char *str, char *buffer, int buffer_size)
{
	int		total_size;
	char	*res;

	total_size = ft_strlen(str) + buffer_size;
	res = (char *)malloc(sizeof(char) * (total_size + 1));
	res[0] = '\0';
	ft_strcat(res, str);
	ft_strncat_buffer(res, buffer, (unsigned int)buffer_size);
	return (res);
}
