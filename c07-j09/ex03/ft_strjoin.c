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
#include <errno.h>

static unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strdup(char *src)
{
	unsigned int	src_size;
	char			*result;

	src_size = ft_strlen(src) + 1;
	result = (char *)malloc((sizeof(char) * src_size) + 1);
	if (result == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (ft_strcpy(result, src));
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int				i;
	unsigned int	total_size;
	unsigned int	sep_size;
	char			*result;

	i = 0;
	total_size = 0;
	sep_size = ft_strlen(sep);
	if (size == 0)
		return (ft_strdup(""));
	while (i < size)
		total_size = total_size + sep_size + ft_strlen(strs[i++]);
	result = (char *)malloc((sizeof(char) * (total_size - sep_size)) + 1);
	result[0] = '\0';
	result[total_size] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
