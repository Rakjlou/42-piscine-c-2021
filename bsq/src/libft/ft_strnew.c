/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:49:35 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 14:39:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str_new;

	str_new = malloc(sizeof(char) * (size + 1));
	if (str_new)
	{
		ft_bzero(str_new, size + 1);
		return (str_new);
	}
	else
		return (NULL);
}
