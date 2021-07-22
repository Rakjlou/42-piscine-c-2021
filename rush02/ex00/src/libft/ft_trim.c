/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:50:36 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:50:36 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim(char *str)
{
	int	i;
	int	j;

	j = ft_strlen(str) - 1;
	i = 0;
	while (ft_char_is_space(str[i]))
		i++;
	while (j > 0 && j > i && ft_char_is_space(str[j]))
		j--;
	return (ft_strndup(str + i, (j - i) + 1));
}

char	*ft_trim_left(char *str)
{
	int	i;

	i = 0;
	while (ft_char_is_space(str[i]))
		i++;
	return (ft_strdup(str + i));
}

char	*ft_trim_right(char *str)
{
	int	j;

	j = ft_strlen(str) - 1;
	while (j > 0 && ft_char_is_space(str[j]))
		j--;
	return (ft_strndup(str, j + 1));
}
