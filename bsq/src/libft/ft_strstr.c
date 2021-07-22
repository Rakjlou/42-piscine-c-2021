/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:03:50 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/05 14:03:51 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_is_found(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (1);
	else if (*str == *to_find)
		return (ft_is_found(str + 1, to_find + 1));
	else
		return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;

	if (*to_find == 0)
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_found(str + i, to_find))
			return (str + i);
		i++;
	}
	return (NULL);
}
