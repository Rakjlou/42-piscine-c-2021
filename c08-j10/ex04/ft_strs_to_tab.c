/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 02:25:16 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/09 02:25:17 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <errno.h>

static int	ft_strlen(char *str)
{
	int	i;

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

char	*ft_strdup(char *src)
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

void	hydrate_stock_str(t_stock_str *sstr, char *str)
{
	if (str == NULL)
	{
		sstr->str = 0;
		sstr->copy = 0;
		sstr->size = 0;
	}
	else
	{
		sstr->str = str;
		sstr->copy = ft_strdup(str);
		sstr->size = ft_strlen(str);
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*result;

	i = 0;
	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (result == NULL)
		return (NULL);
	while (av[i] != 0 && i < ac)
	{
		hydrate_stock_str(result + i, av[i]);
		i++;
	}
	hydrate_stock_str(result + i, 0);
	return (result);
}
