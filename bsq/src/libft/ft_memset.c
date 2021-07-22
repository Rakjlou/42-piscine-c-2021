/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:34:13 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 10:05:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s_cursor;

	s_cursor = (char *)s;
	while (n-- != 0)
	{
		*s_cursor = (char)c;
		s_cursor++;
	}
	return (s);
}
