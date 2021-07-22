/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitize_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:50:27 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:50:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sanitize_number(char *number)
{
	int	i;
	int	start;

	i = 0;
	while (ft_char_is_space(number[i]))
		i++;
	if (number[i] == '+')
		i++;
	start = i;
	while (number[i] >= '0' && number[i] <= '9')
		i++;
	number[i] = '\0';
	return (number + start);
}
