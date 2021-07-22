/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:04:04 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/05 14:04:05 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size_src;
	unsigned int	size_dest;

	size_src = ft_strlen(src);
	size_dest = ft_strlen(dest);
	i = 0;
	j = 0;
	if (size == 0)
		return (size_src);
	else if (size <= size_dest)
		return (size + size_src);
	while (dest[i])
		i++;
	while (src[j] != '\0' && (i + j) < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (size_src + size_dest);
}
