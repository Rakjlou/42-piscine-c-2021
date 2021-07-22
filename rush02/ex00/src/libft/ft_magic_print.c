/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:50:25 by nsierra-          #+#    #+#             */
/*   Updated: 2021/07/18 21:50:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_magic_print(char *str)
{
	static int	first = 1;
	int			first_space;
	int			i;

	first_space = 1;
	i = 0;
	if (first == 0)
		write(1, " ", 1);
	first = 0;
	while (str[i])
	{
		if (ft_char_is_space(str[i]) && first_space == 1)
		{
			first_space = 0;
			write(1, str + i, 1);
		}
		else if (!ft_char_is_space(str[i]))
		{
			while (str[i] && !ft_char_is_space(str[i]))
				write(1, str + i++, 1);
			first_space = 1;
		}
		else
			i++;
	}
}

void	ft_magic_print2(char *str, char *str2)
{
	ft_magic_print(str);
	ft_magic_print(str2);
}
