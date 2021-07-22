/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:00:05 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:52:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <errno.h>

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char	*ft_strndup(char *src, int len)
{
	char			*result;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	result[len] = '\0';
	return (ft_strncpy(result, src, len));
}
